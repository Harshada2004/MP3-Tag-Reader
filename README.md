# MP3 Tag Reader and Editor Using C

## 📌 Overview

**MP3 Tag Reader and Editor** is a C-based application used to read and modify metadata stored in MP3 audio files.

The project works with **ID3 tags**, which contain information such as the **song title, artist, album, year, genre, and comments**. It provides a simple way to view and update this metadata directly from the terminal.

## ✨ Features

* Read MP3 metadata
* Display ID3 tag information
* Edit existing MP3 metadata
* Update individual tag fields
* Supports common ID3 information such as:

  * Title
  * Artist
  * Album
  * Year
  * Genre
  * Comment
* Command-line based interface
* Handles binary MP3 file operations

## 🛠️ Technologies Used

* Language:C
* File Format: MP3
* Metadata Format: ID3
* Concepts: File Handling, Structures, Pointers, Strings
* Compiler: GCC
* Platform: Linux

## 🧠 What are ID3 Tags?

ID3 is a metadata format used to store information about an MP3 audio file.

For example:

```text
+--------------------------------+
|          MP3 File              |
+--------------------------------+
| Title   : Shape of You         |
| Artist  : Ed Sheeran           |
| Album   : Divide               |
| Year    : 2017                 |
| Genre   : Pop                  |
| Comment : Music                |
+--------------------------------+
```

The MP3 Tag Reader accesses these metadata fields and displays or modifies their values.

## ⚙️ Working

### Read Operation

The program:

1. Opens the MP3 file in binary read mode.
2. Reads the ID3 tag information.
3. Extracts individual metadata fields.
4. Displays the tag values to the user.

### Edit Operation

The program:

1. Opens the MP3 file.
2. Reads the existing ID3 information.
3. Accepts the new value from the user.
4. Updates the selected tag.
5. Writes the modified metadata back to the MP3 file.

## 🔄 Project Workflow

```text
                 MP3 File
                    │
                    ↓
              Read ID3 Tags
                    │
          ┌─────────┴─────────┐
          ↓                   ↓
       Display              Edit
          │                   │
          │             New Tag Value
          │                   │
          │                   ↓
          │             Update Tag
          │                   │
          └─────────┬─────────┘
                    ↓
              Updated MP3 File
```

## 📋 Supported Tags

| Tag    | Description |
| ------ | ----------- |
| `TIT2` | Song Title  |
| `TPE1` | Artist      |
| `TALB` | Album       |
| `TYER` | Year        |
| `TCON` | Genre       |
| `COMM` | Comment     |

> The exact supported tags depend on the implementation.

## 💻 Example

### Read MP3 Tags

```text
========== MP3 TAG READER ==========

Title   : Perfect
Artist  : Ed Sheeran
Album   : Divide
Year    : 2017
Genre   : Pop
Comment : -
```

### Edit MP3 Tag

```text
Enter the tag to edit:
1. Title
2. Artist
3. Album
4. Year
5. Genre
6. Comment

Enter your choice: 1

Enter new Title: Perfect - Ed Sheeran
```

The selected metadata field is then updated in the MP3 file.

## 📂 Project Structure

```text
MP3-Tag-Reader/
│
├── main.c
├── mp3_reader.c
├── mp3_reader.h
├── mp3_edit.c
├── mp3_edit.h
├── types.h
└── README.md
```

> Update the file names according to your actual repository structure.

## ▶️ Compilation

Compile the project using GCC:

```bash
gcc *.c -o mp3_tag_reader
```

## 🚀 Execution

```bash
./mp3_tag_reader
```

The program accepts the MP3 file and operation according to the command-line/input format implemented in the project.

## 🧠 Concepts Learned

* File Handling in C
* Binary File Operations
* Structures
* Pointers
* String Manipulation
* Command-Line Arguments
* Metadata Processing
* ID3 Tag Structure
* Modular Programming
* Error Handling

## 🎯 Learning Outcomes

* Learned how metadata is stored inside MP3 files.
* Gained practical experience with binary file handling.
* Understood the basic structure and purpose of ID3 tags.
* Implemented reading and modification of MP3 metadata.
* Improved pointer, structure, and file-handling skills.
* Strengthened debugging and problem-solving abilities.

## ⚡ Advantages

* Simple command-line interface.
* Allows quick viewing of MP3 metadata.
* Provides functionality to modify tag information.
* Demonstrates practical binary file processing.
* Lightweight C-based implementation.

## ⚠️ Limitations

* Supports only the ID3 tags implemented in the project.
* Designed primarily for MP3 files.
* Compatibility may vary depending on the ID3 version and MP3 file.
* Does not modify audio data itself.

## 🔮 Future Enhancements

* Support for additional ID3 versions.
* Add album-art reading and editing.
* Support batch editing of multiple MP3 files.
* Add more metadata fields.
* Improve error handling and validation.
* Develop a graphical user interface.

## 👩‍💻 Author

Harshada Wani

### Project

MP3 Tag Reader and Editor Using C

A practical C project demonstrating **Binary File Handling, Structures, Pointers, Metadata Processing, and ID3 Tag Manipulation**.
