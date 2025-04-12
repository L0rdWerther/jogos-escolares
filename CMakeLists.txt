cmake_minimum_required(VERSION 3.10)
project(MeuProjeto VERSION 1.0 LANGUAGES C)

set(SOURCE_FILES main.c atleta.c equipe.c modalidade.c torneio.c jogos.c)
add_executable(MeuProjeto ${SOURCE_FILES})

target_include_directories(MeuProjeto PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})