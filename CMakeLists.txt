cmake_minimum_required( VERSION 2.7.0 )

SET (CMAKE_C_FLAGS "--std=gnu99 ${CMAKE_C_FLAGS}")


SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY build/)
SET(CMAKE_INSTALL_PREFIX, out)

file(GLOB AllSources src/*.c)
file(GLOB AllHeaders src/*.h)
file(GLOB TestSources tests/*.c)

add_library(lgc_lib ${AllSources} src/allocator.h)

install(TARGETS lgc_lib DESTINATION lib)
install(FILES ${AllHeaders} DESTINATION include)

enable_testing()
foreach(testSrc ${TestSources})
  get_filename_component(testName ${testSrc} NAME_WE)

  add_executable(${testName} ${testSrc})
  target_link_libraries(${testName} lgc_lib)

  add_test(${testName} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${testName})
endforeach(testSrc)
