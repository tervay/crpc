load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

http_archive(
    name = "rules_proto_grpc",
    sha256 = "28724736b7ff49a48cb4b2b8cfa373f89edfcb9e8e492a8d5ab60aa3459314c8",
    strip_prefix = "rules_proto_grpc-4.0.1",
    urls = ["https://github.com/rules-proto-grpc/rules_proto_grpc/archive/4.0.1.tar.gz"],
)

load("@rules_proto_grpc//:repositories.bzl", "rules_proto_grpc_repos", "rules_proto_grpc_toolchains")

rules_proto_grpc_toolchains()

rules_proto_grpc_repos()

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

load("@rules_proto_grpc//cpp:repositories.bzl", rules_proto_grpc_cpp_repos = "cpp_repos")

rules_proto_grpc_cpp_repos()

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

http_archive(
    name = "com_google_absl",
    strip_prefix = "abseil-cpp-72c765111173a61de6e4184bb837f855b7869952",
    urls = ["https://github.com/abseil/abseil-cpp/archive/72c765111173a61de6e4184bb837f855b7869952.zip"],
)

http_archive(
    name = "rules_cc",
    strip_prefix = "rules_cc-262ebec3c2296296526740db4aefce68c80de7fa",
    urls = ["https://github.com/bazelbuild/rules_cc/archive/262ebec3c2296296526740db4aefce68c80de7fa.zip"],
)

http_archive(
    name = "com_google_googletest",
    strip_prefix = "googletest-011959aafddcd30611003de96cfd8d7a7685c700",
    urls = ["https://github.com/google/googletest/archive/011959aafddcd30611003de96cfd8d7a7685c700.zip"],
)

http_archive(
    name = "com_github_google_benchmark",
    sha256 = "2a778d821997df7d8646c9c59b8edb9a573a6e04c534c01892a40aa524a7b68c",
    strip_prefix = "benchmark-bf585a2789e30585b4e3ce6baf11ef2750b54677",
    urls = ["https://github.com/google/benchmark/archive/bf585a2789e30585b4e3ce6baf11ef2750b54677.zip"],
)

http_archive(
    name = "cpr",
    build_file = "//src/include/cpr:BUILD",
    # sha256 = "656ee0b0d6d79280a0aa6f58c08bb2afdc0b67fd745c3c405b3453bd195e14dd",
    strip_prefix = "cpr-f4622efcb59d84071ae11404ae61bd821c1c344b",
    urls = [
        "https://github.com/Unilang/cpr/archive/f4622efcb59d84071ae11404ae61bd821c1c344b.tar.gz",
    ],
)

http_archive(
    name = "curl",
    build_file = "//src/include/curl:BUILD",
    patches = [
        "//src/include/curl/patches:p1.patch",
    ],
    sha256 = "3f6c54fb691853e9b00ed484ea2f52566c7af172ecd48cd9eeec8041a9ac679b",
    strip_prefix = "curl-11974ac859c5d82def59e837e0db56fef7f6794e",
    urls = [
        "https://github.com/Unilang/curl/archive/11974ac859c5d82def59e837e0db56fef7f6794e.tar.gz",
    ],
)

http_archive(
    name = "zlib",
    build_file = "//src/include/zlib:BUILD",
    sha256 = "6d4d6640ca3121620995ee255945161821218752b551a1a180f4215f7d124d45",
    strip_prefix = "zlib-cacf7f1d4e3d44d871b605da3b647f07d718623f",
    urls = [
        "https://github.com/Unilang/zlib/archive/cacf7f1d4e3d44d871b605da3b647f07d718623f.tar.gz",
    ],
)

http_archive(
    name = "openssl",
    build_file = "//src/include/openssl:BUILD",
    patches = ["//src/include/openssl/patches:p1.patch"],
    sha256 = "fb6b5de486f1739dc34f2854a0c8f94d13c130eb9c4876cad73b3d40996f8ba6",
    strip_prefix = "openssl-OpenSSL_1_1_1",
    urls = [
        "https://github.com/unilang/openssl/archive/OpenSSL_1_1_1.tar.gz",
        "https://github.com/openssl/openssl/archive/OpenSSL_1_1_1.tar.gz",
    ],
)

# git_repository(
#     name = "com_curoky_rules_pkg",
#     branch = "master",
#     remote = "https://github.com/curoky/rules_cc",
# )

# load("@com_curoky_rules_pkg//:rules_dependencies.bzl", "pkg_rules_dependencies")

# pkg_rules_dependencies()

# load("@com_curoky_rules_pkg//:register_toolchains.bzl", "pkg_register_toolchains")

# pkg_register_toolchains()

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor
http_archive(
    name = "hedron_compile_commands",
    strip_prefix = "bazel-compile-commands-extractor-9d8b3d5925728c3206010ed0062826a9faaebc2c",

    # Replace the commit hash in both places (below) with the latest.
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" below).
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/9d8b3d5925728c3206010ed0062826a9faaebc2c.tar.gz",
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()
