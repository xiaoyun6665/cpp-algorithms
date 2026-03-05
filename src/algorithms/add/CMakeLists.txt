add_library(CAAdd)   # 库名保持与模块名一致

target_sources(CAAdd
    PRIVATE
        FILE_SET CXX_MODULES
        FILES
            Add.ixx
)

# 如果有依赖其他库（无论是模块还是传统库），用 target_link_libraries
# target_link_libraries(algo1 PRIVATE some_dependency)