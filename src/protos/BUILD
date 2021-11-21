load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "models",
    srcs = ["models.proto"],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_protobuf//:empty_proto",
    ],
)

cpp_grpc_library(
    name = "models_cpp",
    protos = [":models"],
    visibility = ["//visibility:public"],
)

proto_library(
    name = "tba",
    srcs = [
        "tba.proto",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":models",
        "@com_google_protobuf//:empty_proto",
    ],
)

cpp_grpc_library(
    name = "tba_cpp",
    protos = [":tba"],
    visibility = ["//visibility:public"],
    deps = [
        ":models_cpp",
    ],
)
