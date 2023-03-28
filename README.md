# tsv2tableplusplus
csv2table++ but for tab separated values!


```bash
$ cat test.tsv
Name	Age
Bart	9
Lisa	7
Maggie	18mo
Marge	32
Homer	35

$ tsv2table++ test.tsv 
Argument Count: 2
Argument0: tsv2table++
Argument1: test.tsv
Empty line ignored.
Empty line ignored.
Elements in result array: 12
Max Columns: 2
Max Rows: 8
Max Cell Size: 8
+---------+---------+
|    Name |     Age |
+---------+---------+
|    Bart |       9 |
|    Lisa |       7 |
|  Maggie |    18mo |
|   Marge |      32 |
|   Homer |      35 |
+---------+---------+
$ 
```

# Issues

Same as csv2table++ - need to work on getting input from STDIN too. So far just works with tsv filename as argument. 
