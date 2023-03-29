# tsv2tableplusplus
csv2table++ but for tab separated values!

# Now doing what I wanted

Which was to take standard input OR an argument filename and process  it accordingly.

```bash
$ tsv2table++
Main Function.
Has Exactly One Argument? false
process_stdin() called
hello   world
foo     bar
Empty line ignored.
make_table() called.
Result array size: 4
Max Cols: 2
Max Rows: 3
Max Cell Size: 7
+--------+--------+
|  hello |  world |
+--------+--------+
|    foo |    bar |
+--------+--------+

$ echo -e "foo\tbar\nfoo\tbar" | tsv2table++
Main Function.
Has Exactly One Argument? false
process_stdin() called
Empty line ignored.
make_table() called.
Result array size: 4
Max Cols: 2
Max Rows: 3
Max Cell Size: 5
+------+------+
|  foo |  bar |
+------+------+
|  foo |  bar |
+------+------+

$ tsv2table++ test.tsv
Main Function.
Has Exactly One Argument? true
process_arg() called on test.tsv
Empty line ignored.
make_table() called.
Result array size: 4
Max Cols: 2
Max Rows: 3
Max Cell Size: 5
+------+------+
|  foo |  bar |
+------+------+
|  foo |  bar |
+------+------+
```

# Issues

Need to work on getting it DRY compliant (do not repeat yourself). 
