#!/bin/bash

# Directory containing source files
SOURCE_DIR="/workspaces/System-Design/5_CreationalPattern/AbstractFactory"
OUTPUT_DIR="$SOURCE_DIR/puml_files"

# Create output directory for .puml files
mkdir -p "$OUTPUT_DIR"

# Generate individual .puml files for each source file
for file in "$SOURCE_DIR"/*.{cxx,hxx}; do
    if [[ -f "$file" ]]; then
        filename=$(basename -- "$file")
        classname="${filename%.*}"
        puml_file="$OUTPUT_DIR/$classname.puml"

        echo "Generating $puml_file"
        echo "@startuml" > "$puml_file"
        echo "class $classname {" >> "$puml_file"

        # Extract member variables (e.g., int x; or std::string name;)
        grep -E "^[[:space:]]*(int|float|double|char|std::string|bool|void|auto)[[:space:]]+[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*;" "$file" | \
        sed -E 's/^[[:space:]]*//;s/[[:space:]]*;/;/g' >> "$puml_file"

        # Extract pure virtual functions (e.g., virtual void foo() = 0;)
        grep -E "^[[:space:]]*virtual[[:space:]]+(int|float|double|char|std::string|bool|void|auto)[[:space:]]+[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*\(.*\)[[:space:]]*=[[:space:]]*0[[:space:]]*;" "$file" | \
        sed -E 's/^[[:space:]]*//;s/[[:space:]]*;/ [pure virtual];/g' >> "$puml_file"

        # Extract overridden functions (e.g., virtual void foo() override;)
        grep -E "^[[:space:]]*virtual[[:space:]]+(int|float|double|char|std::string|bool|void|auto)[[:space:]]+[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*\(.*\)[[:space:]]*override[[:space:]]*;" "$file" | \
        sed -E 's/^[[:space:]]*//;s/[[:space:]]*;/ [override];/g' >> "$puml_file"

        # Extract default functions (e.g., void foo() = default;)
        grep -E "^[[:space:]]*(int|float|double|char|std::string|bool|void|auto)[[:space:]]+[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*\(.*\)[[:space:]]*=[[:space:]]*default[[:space:]]*;" "$file" | \
        sed -E 's/^[[:space:]]*//;s/[[:space:]]*;/ [default];/g' >> "$puml_file"

        echo "}" >> "$puml_file"

        # Detect inheritance (is-a relationship)
        grep -E "class[[:space:]]+$classname[[:space:]]*:[[:space:]]*public[[:space:]]+[a-zA-Z_][a-zA-Z0-9_]*" "$file" | \
        sed -E "s/class[[:space:]]+$classname[[:space:]]*:[[:space:]]*public[[:space:]]+([a-zA-Z_][a-zA-Z0-9_]*)/\1 <|-- $classname/" >> "$puml_file"

        # # Detect associations (has-a relationship)
        # grep -E "^[[:space:]]*[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]+[a-zA-Z_][a-zA-Z0-9_]*;" "$file" | \
        # sed -E "s/^[[:space:]]*([a-zA-Z_][a-zA-Z0-9_]*)[[:space:]]+([a-zA-Z_][a-zA-Z0-9_]*)[[:space:]]*;/\1 --> $classname : has-a/" >> "$puml_file"

        # # Detect dependencies (uses relationship)
        # grep -E "[[:space:]]*[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*\([[:space:]]*[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*\);" "$file" | \
        # sed -E "s/^[[:space:]]*([a-zA-Z_][a-zA-Z0-9_]*)[[:space:]]*\([[:space:]]*([a-zA-Z_][a-zA-Z0-9_]*)[[:space:]]*\);/\1 ..> $classname : uses/" >> "$puml_file"

        echo "@enduml" >> "$puml_file"
    fi
done

# Combine all .puml files into one without duplicates
COMBINED_PUML="$SOURCE_DIR/combined.puml"
echo "@startuml" > "$COMBINED_PUML"

# Use a temporary file to track added classes
TEMP_FILE=$(mktemp)
for puml_file in "$OUTPUT_DIR"/*.puml; do
    if [[ -f "$puml_file" ]]; then
        # Extract class names from the .puml file
        class_name=$(grep -oP '^class \K\w+' "$puml_file")
        if ! grep -q "^class $class_name" "$TEMP_FILE"; then
            # Add the class to the combined file and track it
            grep -v "@startuml" "$puml_file" | grep -v "@enduml" >> "$COMBINED_PUML"
            echo "class $class_name" >> "$TEMP_FILE"
        else
            echo "Skipping duplicate class: $class_name"
        fi
    fi
done

echo "@enduml" >> "$COMBINED_PUML"

# Clean up temporary file
rm "$TEMP_FILE"

echo "PUML files generated in $OUTPUT_DIR and combined into $COMBINED_PUML without duplicates"