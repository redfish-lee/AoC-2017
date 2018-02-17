## [Day 1: Inverse Captcha](http://adventofcode.com/2017/day/1)
Topics: `#readfile` `#ds` `#cast`

### Usage
```bash
$ clang++ inverseCaptcha.cc
$ ./a.out
```

### Troubleshooting
#### [read file not matched](https://softwareengineering.stackexchange.com/questions/318081/why-does-ifstream-eof-not-return-true-after-reading-the-last-line-of-a-file)
```c
while(!infs.eof()) {
    infs >> tmp;
    input.push_back(tmp);
}
-------------------------
2031
```
- This wouldn't stop until it had read the last line of the file **twice**, which means it might get into while loop 1 extra time.

```c
while(infs >> tmp) {
    input.push_back(tmp);
}
-------------------------
2030
```
- Using `eof()` in a loop condition is always not suggested.
- `eof()` doesn't return `true` **until after a failed read**. [check this out](http://www.cplusplus.com/reference/ios/ios/eof/)

#### ASCII offset
- [ascii table](https://en.wikipedia.org/wiki/ASCII#Printable_characters)
```c
char a = '1'
cout << (int)a          // 49
cout << (int)a - '0'    // 1
```
