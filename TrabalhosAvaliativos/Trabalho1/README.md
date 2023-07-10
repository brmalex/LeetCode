Bruno Martins Alexandre, Turma M1

Exercicio 748 do LeetCode:

Given a string licensePlate and an array of strings words, find the shortest completing word in words.
A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.
For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are "abccdef", "caaacab", and "cbca".
Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, return the first one that occurs in words.

Testei 3 casos: <br>
licensePlate = "1s3 PSt", words = \["step","steps","stripe","stepple"] <br>
licensePlate = "1s3 456", words = \["looks","pest","stew","show"] <br>
licensePlate = "Ah71752", words = \["suggest","letter","of","husband","easy","education","drug","prevent","writer","old"]

Todos eles funcionaram.
