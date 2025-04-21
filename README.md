# Substitution and Transposition Ciphers
## Computer Security - University of Brasília

## Author
<p>Lucas Gabriel de Oliveira Lima - 231003406<p>
<table>
    <tr>
        <td align="center"><a href="https://github.com/lucasdbr05" target="_blank"><img style="border-radius: 50%;" src="https://github.com/lucasdbr05.png" width="100px;" alt="Lucas Lima"/><br /><sub><b>Lucas Lima</b></sub></a><br /></td>
</table>

## Run

Linux:
```shell
g++ -std=c++17 -o main main.cpp
./main
```

Windows:
```shell
g++ -std=c++17 -o main main.cpp
./main.exe
```

<h4>
When running the project, the following command interface will appear in the terminal:
</h4>

```shell
Select Option:

T - Change to input from user
0 - Stop
1A - Encrypt using Ceasar Cipher (substitution)
1B - Decrypt using Ceasar Cipher(substitution)
1C - Break shift cipher by brute force
1D - Break shift cipher by frequency distribution
2A - Encrypt using Columnar Permutation Cipher (transposition)
2B - Decrypt using Columnar Permutation Cipher (transposition)
2C - Break columnar permutation by brute force
2D - Break columnar permutation by frequency distribution
```
<h4>The commands are described as follows:</h4>
<ul>
        <li>T: Modifies the input source (either from the user or text files)</li>
        <li>0: stops the program</li>
        <li>Starting with 1: performs operations related to substitution cipher</li>
        <li>Starting with 2: performs operations related to transposition cipher</li>
</ul>
