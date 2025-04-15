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
./main.out
```


Windows:
```shell
g++ -std=c++17 -o main main.cpp
./main.exe
```

<h4>
Ao executar o projeto, aparecerá no terminal a seguinte interface de comandos:
</h4>

```shell
T - Change to input from user 
0 - Stop
1A - Encrypt using Ceasar Cipher (substitution)
1B - Decrypt using Ceasar Cipher (substitution)
1C - Break shift cipher by brute force
1D - Break shift cipher by frequency distribution
2A - Encrypt using Rails Fence Cipher (transposition)
2B - Decrypt using Rails Fence Cipher (transposition)
2C - Break rails fence by brute force
2D - Break rails fece by frequency distribution
```
<h4>Os comandos são descritos a seguir:</h4>
<ul>
    <li>T: Modifica a fonte dos inputs (ou do usuário ou dos arquivos de texto)</li>
    <li>0: para o programa</li>
    <li>Iniciadas em 1: realiza operações relacionadas à cifra de substituição</li>
    <li>Iniciadas em 2: realiza operações relacionadas à cifra de transposição0</li>
</ul>