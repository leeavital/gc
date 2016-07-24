cmake_minimum_required( VERSION 3.5.0 )

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY build/)


file(GLOB AllSources src/*.c)
file(GLOB TestSources tests/*.c)

add_library(thelib ${AllSources})

enable_testing()
foreach(testSrc ${TestSources})
  get_filename_component(testName ${testSrc} NAME_WE)

  add_executable(${testName} ${testSrc})
  target_link_libraries(${testName} thelib)

  add_test(${testName} ${testName})
endforeach(testSrc)
