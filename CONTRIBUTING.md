# Contributing to LiteXfer

Thank you for considering contributing to **LiteXFer**! Your input and expertise help make this project better. This guide outlines the process to help you contribute effectively.

---

## Table of Contents

1. [Code of Conduct](#code-of-conduct)  
2. [How Can You Contribute?](#how-can-you-contribute)  
3. [Getting Started](#getting-started)  
4. [Development Guidelines](#development-guidelines)  
5. [Reporting Issues](#reporting-issues)  
6. [Submitting Pull Requests](#submitting-pull-requests)  
7. [Style Guide](#style-guide)  

---

## Code of Conduct

Please adhere to the [Code of Conduct](CODE_OF_CONDUCT.md) to ensure a welcoming and inclusive environment. By participating, you agree to maintain respect and professionalism toward all contributors.

---

## How Can You Contribute?

There are several ways you can contribute to **LiteXfer**:

- Report bugs and suggest enhancements.
- Contribute code to fix bugs or add new features.
- Improve documentation or add examples/tutorials.
- Help review existing pull requests.
- Provide feedback on design decisions.

---

## Getting Started

1. **Fork the Repository**  
   Click the `Fork` button in the top-right corner of the repository page to create your copy.

2. **Clone Your Fork**  
   ```bash
   git clone https://github.com/rcallaby/LiteXfer.git
   cd LiteXfer
   ```

3. **Set Upstream Repository**  
   ```bash
   git remote add upstream https://github.com/rcallaby/LiteXfer.git
   ```

4. **Install Dependencies**  
   Ensure your development environment is ready:
   - **Linux:** Install a C++ compiler (e.g., GCC) and CMake.
   - **Windows:** Use Visual Studio or MinGW.
   - **MacOS:** Install Xcode or Homebrew with GCC/Clang.

   To build the project:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
---

## Development Guidelines

### Key Areas to Contribute

- **Core HTTP Functionality:** Improve request handling, file transfer capabilities, or protocol support.
- **Cross-Platform Compatibility:** Enhance support for Windows and MacOS.
- **Performance Optimization:** Make the server faster and more efficient.
- **Security Improvements:** Address vulnerabilities or add secure transfer protocols.
- **Documentation:** Provide clear instructions, examples, and tutorials.

### Branching Strategy

- **Main Branch (`main`)**: Stable, production-ready code.  
- **Feature Branches (`feature/xyz`)**: For developing new features or major fixes.  
- **Bugfix Branches (`bugfix/xyz`)**: For resolving specific issues.  

Before starting work on a feature, ensure an issue exists, or create one. This helps track progress and avoids duplication.

### Commit Message Format

Use clear and descriptive commit messages:
```plaintext
[Category] Short description (50 chars or less)

More detailed explanation (if necessary).
```
**Examples:**
- `[Feature] Add support for HTTPS file transfers.`
- `[Bugfix] Fix segmentation fault on large file uploads.`

---

## Reporting Issues

If you encounter a problem, please [open an issue](https://github.com/rcallaby/LiteXfer/issues) and include:

1. A clear title and description.
2. Steps to reproduce the issue.
3. The expected behavior.
4. Your environment (OS, compiler version, etc.).
5. Any relevant logs or screenshots.

---

## Submitting Pull Requests

1. **Sync Your Fork**
   Before starting your work, update your fork with the latest changes:
   ```bash
   git checkout main
   git fetch upstream
   git merge upstream/main
   ```

2. **Create a Feature Branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **Write Code and Commit**
   Commit your changes following the commit message format.

4. **Push to Your Fork**
   ```bash
   git push origin feature/your-feature-name
   ```

5. **Open a Pull Request**
   - Navigate to your fork on GitHub.
   - Click the "New Pull Request" button.
   - Describe your changes and link any relevant issues.

6. **Review and Merge**
   - Address feedback promptly.
   - Squash commits if requested.

---

## Style Guide

- **Language Standard:** C++17 or newer.  
- **Formatting:** Use [clang-format](https://clang.llvm.org/docs/ClangFormat.html) with the provided `.clang-format` file.  
- **Naming Conventions:**  
  - Classes: `PascalCase`
  - Functions: `camelCase`
  - Variables: `snake_case`
- **Comments:** Use Doxygen-style comments for all public APIs.

---

We appreciate your support and contributions to **LiteXfer**! Together, we can build something amazing. 😊  

---

By contributing to this project, you agree to license your contributions under the same license as this project.

--- 

