CMAKE_MINIMUM_REQUIRED( VERSION 3.5.0 )

FILE(GLOB AllSources src/*.c)
FILE(GLOB TestSources tests/*.c)


add_library(thelib ${AllSources})

enable_testing()
foreach(testSrc ${TestSources})
  get_filename_component(testName ${testSrc} NAME_WE)

  add_executable(${testName} ${testSrc})
  target_link_libraries(${testName} thelib)

  add_test(${testName} ${testName})
endforeach(testSrc)
