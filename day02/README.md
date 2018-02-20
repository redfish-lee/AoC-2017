## [Day 2: Corruption Checksum](http://adventofcode.com/2017/day/2)
Topics: `#readfile` `#string`

### Usage
```bash
$ clang++ -std=c++11 corruptionChecksum.cc
$ ./a.out
```

## Concepts
### Copy a string (char array)
[strdup (danamic) copy a char array](http://en.cppreference.com/w/c/experimental/dynamic/strdup)

```c
// char * strdup(const char *str1);
char* ptr1 = "this is a string";
char* ptr2 = strdup(ptr1);

free(ptr2);   // necessary
```

### Pass a string to function
- [Reference](https://stackoverflow.com/a/4475691/8426713)

```c
// pass by string
void customPrint(const string& input) {
    cout << input << endl;
}

void customPrint(const char* input) {
    cout << input << endl;
}

string str = "this is a test";
customPrint(str);           // pass string directly
customPrint(str.c_str());   // pass char* 
```

### tokenizer
- `strtok` needs a mutable input, so `const char*` may cause error. Use `char *` instead.
- `atoi` is for `const char*` as input
- `stoi` is for `std::string` as input