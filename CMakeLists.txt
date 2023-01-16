cmake_minimum_required(VERSION 3.24)
project(tcp_server_client C)

set(CMAKE_C_STANDARD 11)

add_executable(tcp_server_client main.c server.c header.h client.c)
