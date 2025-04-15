# Homework.
Егор Шастин Олегович, gruppa b81-mm
Contact: st129457@student.spbu.ru,egor.shast0.0@gmail.com

# Decoder Project

## Overview

This C++ program is an ASCII85 decoder. It takes an input string encoded in ASCII85 format, processes it by decoding each block of characters, and converts the encoded string back into the original binary data. It prints the decoded data as raw bytes.

## Table of Contents
- [Installation and Build](#installation-and-build)
- [Tests](#tests)

## Installation and Build

### Building the Project

```sh
make
```

### Running the Decoder
To start the programm, run the compiled executable:

```sh
./bin/Start -d # Run for decoder
./bin/Start -e # Run for encoder
```

## Tests

#### Continuous Integration (CI)
This project uses GitHub Actions for automated builds and testing. All tests are run in the CI pipeline on every commit.

#### Running Tests Locally
To run tests locally, you can use the following commands:

```sh
make test    # Runs tests for all programm
```

