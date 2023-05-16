
<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br>
push_swap
</h1>
<img src="https://github.com/junyjeon/fdf/assets/98337069/e4cb1b68-eaaf-453e-b1c9-5b8b8033604d" />
<h3 align="center">📍 Push your code to new heights with Push_Swap!</h3>
<h3 align="center">🚀 Developed with the software and tools below.</h3>
<p align="center">

<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=for-the-badge&logo=C&logoColor=black" alt="" />
</p>

</div>

---
## 📚 Table of Contents
- [📚 Table of Contents](#-table-of-contents)
- [📍Overview](#-introdcution)
- [🔮 Features](#-features)
- [⚙️ Project Structure](#project-structure)
- [🧩 Modules](#modules)
- [🏎💨 Getting Started](#-getting-started)
- [🗺 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [🪪 License](#-license)
- [📫 Contact](#-contact)
- [🙏 Acknowledgments](#-acknowledgments)

---

## 📍Overview

GitHub project push_swap is a program that sorts a given stack of integers using a selection of steps, aiming to minimize the total number of moves required.

## 🔮 Feautres

> `[📌  INSERT-PROJECT-FEATURES]`

---

<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-github-open.svg" width="80" />

## ⚙️ Project Structure

```bash
repo
├── Makefile
├── includes
│   └── push_swap.h
└── sources
    ├── command
    │   ├── push.c
    │   ├── reverse_rotate.c
    │   ├── rotate.c
    │   └── swap.c
    ├── hardcoding
    │   ├── hard_coding.c
    │   ├── sort_five.c
    │   ├── sort_four.c
    │   └── sort_three.c
    ├── main.c
    ├── parsing
    │   ├── check_overlap.c
    │   ├── init.c
    │   ├── parse.c
    │   ├── print_error.c
    │   ├── push_pop.c
    │   └── ranked.c
    ├── quicksort
    │   ├── find_pivot.c
    │   ├── partition.c
    │   ├── quick_sort.c
    │   └── rotation.c
    └── util
        ├── ft_atoi_ll.c
        ├── ft_lstnew.c
        ├── ft_memcpy.c
        ├── ft_split.c
        ├── ft_strdup.c
        ├── ft_strjoin.c
        ├── ft_strlen.c
        ├── ft_strncmp.c
        └── ft_substr.c

7 directories, 30 files
```
---

<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-src-open.svg" width="80" />

## 💻 Modules
<details closed><summary>Command</summary>

| File             | Summary                                                                                                                                                                                                                                                     | Module                           |
|:-----------------|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------------------------|
| rotate.c         | This code implements the rotate functions for two stacks , a and b. It includes functions to rotate both stacks ( rr ) , rotate stack a ( ra ) , and rotate stack b ( rb ) . The rotate functions move the last element of the stack to the                 | sources/command/rotate.c         |
| reverse_rotate.c | This code implements the reverse rotate operations for the push_swap project . It includes functions to reverse rotate both stacks ( rrr ) , reverse rotate the second stack ( rrb ) , and reverse rotate the first stack ( rra ) . It also includes        | sources/command/reverse_rotate.c |
| push.c           | This code implements the push and pop functions for two stacks , a and b. The push and pop functions add and remove elements from the back of the stack respectively . The flag parameter is used to determine whether to print the push and pop commands . | sources/command/push.c           |
| swap.c           | This code implements the swap function for two stacks , a and b. It includes functions to swap both stacks ( ss ) , stack a ( sa ) , and stack b ( sb ) . The flag parameter is used to determine whether to print the command or not                       | sources/command/swap.c           |

</details>

<details closed><summary>Hardcoding</summary>

| File          | Summary                                                                                                                                                                                                                        | Module                           |
|:--------------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------------------------|
| sort_five.c   | This code is a sorting algorithm for five elements in a stack . It uses the quick sort algorithm to sort the elements in the stack , and then uses the quick sort stack b algorithm to sort the elements in the second stack . | sources/hardcoding/sort_five.c   |
| sort_four.c   | This code is a sorting algorithm for four elements in a stack . It uses the push_swap library to compare and move elements between two stacks , and then sorts them in ascending order .                                       | sources/hardcoding/sort_four.c   |
| hard_coding.c | This code is a function that sorts a stack of numbers of size 1 - 5 . It uses hard - coding to sort the stack , using different sorting algorithms depending on the size of the stack .                                        | sources/hardcoding/hard_coding.c |
| sort_three.c  | This code is a sorting algorithm for three elements in a stack . It uses the push_swap library to compare the elements and sort them in ascending order . It uses the sb , rb , rrb , sa , ra , and                            | sources/hardcoding/sort_three.c  |

</details>

<details closed><summary>Includes</summary>

| File        | Summary                                                                                                                                                                                                                  | Module               |
|:------------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------------|
| push_swap.h | This code is a header file for the push_swap program , which is used to sort a stack of numbers . It includes functions for manipulating the stack , such as push_front , pop_back , and sa . It also includes functions | includes/push_swap.h |

</details>

<details closed><summary>Parsing</summary>

| File            | Summary                                                                                                                                                                                                                        | Module                          |
|:----------------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:--------------------------------|
| parse.c         | This code parses command line arguments and creates a linked list of integers . It also checks for duplicate values and sorts the list in ascending order .                                                                    | sources/parsing/parse.c         |
| check_overlap.c | This code checks for overlapping elements in an array of integers and prints an error if any are found . It sorts the array and then checks each element against the next one to see if they are the same .                    | sources/parsing/check_overlap.c |
| init.c          | This code initializes the pivot , count , stack , and compare variables . It sets the min and max of the pivot to 0 , the sa , sb , ra , rb , pa , and pb of the count to 0 ,                                                  | sources/parsing/init.c          |
| push_pop.c      | This code is a set of functions that allow for the manipulation of a doubly linked list stack . The functions include push_front , push_back , pop_front , and pop_back , which allow for the addition and removal of elements | sources/parsing/push_pop.c      |
| print_error.c   | This code is a function that prints an error message and exits the program . It takes in a string and a flag as parameters . If the flag is set to 1 , the string is printed and the program exits with a status of 1 . If     | sources/parsing/print_error.c   |
| ranked.c        | This code creates a ranked list of values in a stack , based on an array of values . It iterates through the stack and assigns each value a rank based on its position in the array . It then frees the array .                | sources/parsing/ranked.c        |

</details>

<details closed><summary>Quicksort</summary>

| File         | Summary                                                                                                                                                                                                                                     | Module                         |
|:-------------|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:-------------------------------|
| find_pivot.c | This code creates a function to find the pivot of a stack . It takes in a stack , size , and pivot as parameters . It creates an array of the stack 's ranks , sorts it , and sets the min and max of the pivot to                          | sources/quicksort/find_pivot.c |
| quick_sort.c | This code is a quick sort algorithm for sorting a stack of numbers . It uses a partitioning method to divide the stack into two parts , and then recursively sorts each part . It also includes a function to check if the stack is already | sources/quicksort/quick_sort.c |
| partition.c  | This code is a function that partitions a stack into two parts based on a pivot value . It takes in two stacks , a counter , and the size of the stack as parameters . It finds the pivot value and then moves elements from one stack to   | sources/quicksort/partition.c  |
| rotation.c   | This code is a function that rotates two stacks , a and b , based on the number of rotations specified in the cnt struct . It uses the rrr , rra , and rrb functions to rotate the stacks .                                                 | sources/quicksort/rotation.c   |

</details>

<details closed><summary>Sources</summary>

| File   | Summary                                                                                                                                                                                                                                    | Module         |
|:-------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------|
| main.c | This code is a main function for a program that sorts a stack of numbers using the Push_Swap algorithm . It initializes two stacks , parses the arguments , ranks the numbers , and then sorts the stack using either hard coding or quick | sources/main.c |

</details>

<details closed><summary>Util</summary>

| File         | Summary                                                                                                                                                                                                                            | Module                    |
|:-------------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:--------------------------|
| ft_memcpy.c  | This code is a function that copies n bytes from the memory area pointed to by src to the memory area pointed to by dest . It includes a header file and returns the destination memory area .                                     | sources/util/ft_memcpy.c  |
| ft_substr.c  | This code creates a substring from a given string , starting at a given index and with a given length . It allocates memory for the substring and returns a pointer to it .                                                        | sources/util/ft_substr.c  |
| ft_strdup.c  | This code creates a duplicate of a given string using malloc and ft_memcpy . It returns a pointer to the duplicate string .                                                                                                        | sources/util/ft_strdup.c  |
| ft_lstnew.c  | This code creates a new element of type t_info , which contains a value , rank , and pointers to the previous and next elements in the list . It takes an integer value as an argument and returns a pointer to the new element .  | sources/util/ft_lstnew.c  |
| ft_strlen.c  | This code is a function that returns the length of a given string . It takes in a string as an argument and returns the length of the string as a size_t .                                                                         | sources/util/ft_strlen.c  |
| ft_strncmp.c | This code is a function that compares two strings up to a certain number of characters and returns the difference between them . It takes in two strings and a size_t n as parameters .                                            | sources/util/ft_strncmp.c |
| ft_atoi_ll.c | This code is a function that converts a string to an integer . It checks for valid input , and if the integer is out of range , it prints an error message . It also handles negative numbers .                                    | sources/util/ft_atoi_ll.c |
| ft_split.c   | This code is a function that splits a string into an array of strings based on a given character . It takes in a string and a character as parameters and returns an array of strings . It also handles memory allocation errors . | sources/util/ft_split.c   |
| ft_strjoin.c | This code creates a new string by joining two strings , s1 and s2 , together . It allocates memory for the new string , copies the characters from s1 and s2 into the new string , and adds a space character at the               | sources/util/ft_strjoin.c |

</details>
<hr />

## 🚀 Getting Started

### ✅ Prerequisites

Before you begin, ensure that you have the following prerequisites installed:
> `[📌  INSERT-PROJECT-PREREQUISITES]`

### 💻 Installation

1. Clone the push_swap repository:
```sh
git clone https://github.com/junyjeon/push_swap
```

2. Change to the project directory:
```sh
cd push_swap
```

3. Install the dependencies:
```sh
gcc -o myapp main.c
```

### 🤖 Using push_swap

```sh
./myapp
```

### 🧪 Running Tests
```sh
#run tests
```

<hr />

## 🛠 Future Development
- [X] [📌  COMPLETED-TASK]
- [ ] [📌  INSERT-TASK]
- [ ] [📌  INSERT-TASK]


---

## 🤝 Contributing
Contributions are always welcome! Please follow these steps:
1. Fork the project repository. This creates a copy of the project on your account that you can modify without affecting the original project.
2. Clone the forked repository to your local machine using a Git client like Git or GitHub Desktop.
3. Create a new branch with a descriptive name (e.g., `new-feature-branch` or `bugfix-issue-123`).
```sh
git checkout -b new-feature-branch
```
4. Make changes to the project's codebase.
5. Commit your changes to your local branch with a clear commit message that explains the changes you've made.
```sh
git commit -m 'Implemented new feature.'
```
6. Push your changes to your forked repository on GitHub using the following command
```sh
git push origin new-feature-branch
```
7. Create a pull request to the original repository.
Open a new pull request to the original project repository. In the pull request, describe the changes you've made and why they're necessary.
The project maintainers will review your changes and provide feedback or merge them into the main branch.

---

## 🪪 License

This project is licensed under the `[📌  INSERT-LICENSE-TYPE]` License. See the [LICENSE](https://docs.github.com/en/communities/setting-up-your-project-for-healthy-contributions/adding-a-license-to-a-repository) file for additional info.

---

## 🙏 Acknowledgments

[📌  INSERT-DESCRIPTION]


---

