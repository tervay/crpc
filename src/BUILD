cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "//src/include:HTTPRequest",
        "//src/protos:models_cpp",
        "//src/protos:tba_cpp",
        "@com_google_absl//absl/status",
    ],
)

cc_binary(
    name = "main2",
    srcs = ["main2.cc"],
    deps = [
        "//src/include:HTTPRequest",
        "@com_google_absl//absl/strings:str_format",
    ],
)
