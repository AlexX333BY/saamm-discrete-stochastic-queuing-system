set(HEADERS
        model_parameters_parser.h
)

set(SOURCES
        model_parameters_parser.cpp
)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.67.0 REQUIRED COMPONENTS
        program_options
)

add_executable(DiscreteStohasticQueuingSystemAnalyzer ${HEADERS} ${SOURCES})

target_include_directories(DiscreteStohasticQueuingSystemAnalyzer PRIVATE
        ${Boost_INCLUDE_DIRS}
        ../QueuingSystemLib
)

target_link_libraries(DiscreteStohasticQueuingSystemAnalyzer
        ${Boost_LIBRARIES}
        QueuingSystemLib
)

set_target_properties(DiscreteStohasticQueuingSystemAnalyzer PROPERTIES OUTPUT_NAME "dsqs-analyzer")
