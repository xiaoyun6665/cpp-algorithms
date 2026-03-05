# 下载并构建 Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 包含 GoogleTest 模块以便自动发现测试
include(GoogleTest)

# 添加镜像子目录
add_subdirectory(algorithms)
# add_subdirectory(dataStructures)