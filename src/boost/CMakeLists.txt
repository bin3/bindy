add_executable(cast_main cast_main.cc)
add_executable(format_main format_main.cc)
add_executable(boost_regex_main regex_main.cc)
target_link_libraries(boost_regex_main boost_regex)
add_executable(graph_main graph_main.cc)
add_executable(property_map_main property_map_main.cc)
#add_executable(spirit_main spirit_main.cc)
add_executable(mapped_matrix_main mapped_matrix_main.cc)
add_executable(algo_str_main algo_str_main.cc)
add_executable(timer_main timer_main.cc)
target_link_libraries(timer_main boost_timer boost_system)
add_executable(date_time_main date_time_main.cc)
target_link_libraries(date_time_main boost_date_time)
add_executable(thread_specific_ptr_main thread_specific_ptr_main.cc)
target_link_libraries(thread_specific_ptr_main boost_thread)
add_executable(ublas_main ublas_main.cpp)
