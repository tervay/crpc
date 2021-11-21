```
$ bazel build --experimental_action_listener=//tools/actions:generate_compile_commands_listener //src:main2
$ cd tools/actions
$ python generate_compile_commands_json.py
```