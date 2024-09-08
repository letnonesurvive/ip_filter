# Task 2
## Filtering IP Addresses

The goal of the task is to implement an application that processes a list of IP addresses.
The program reads data from standard input. The data is stored line by line. Each line consists of three fields, separated by a single tab character, and ends with a newline character. The format of the line is:

`text1 \t text2 \t text3 \n`

Fields text2 and text3 are ignored. The text1 field has the following structure (IPv4 address): `n1.n2.n3.n4` where `n1..4` are integers from 0 to 255.

You need to load the list of IP addresses into memory and sort them in reverse lexicographical order. An example of lexicographical sorting (first by the first number, then by the second, and so on):
```
1.1.1.1
1.2.1.1
1.10.1.1
```

Accordingly, reverse order would be:
```
1.10.1.1
1.2.1.1
1.1.1.1
```

Note that sorting is performed in the byte (numeric) representation of the IP address, not the string one. Therefore, for example, the address `1.2.1.1` is less than the address `1.10.1.1` (since `2 < 10`).

Next, output the following to standard output:

1. The full list of addresses after sorting. One line - one address.
2. Immediately followed by the list of addresses where the first byte is equal to 1. The sort order remains unchanged. One line - one address. The lists are not separated.
3. Immediately followed by the list of addresses where the first byte is equal to 46, and the second byte is equal to 70. The sort order remains unchanged. One line - one address. The lists are not separated.
4. Immediately followed by the list of addresses where any byte is equal to 46. The sort order remains unchanged. One line - one address. The lists are not separated.

## Implementation Requirements

In the source file attached to the task, replace constructions where possible with equivalent ones from the C++14/C++17 standard. Implement any missing functionality. It is not necessary to follow the provided template. You may complete the task by structuring the code in any correct manner.
Double-check:

* Lexicographical sorting is understood for both strings and containers.
* The appropriate data structure is chosen for the task.

The `ip_filter` package, containing the executable file `ip_filter`, should be published as a release in the repository.
