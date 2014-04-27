cmake_minimum_required( VERSION 2.6 )

# Устанавливаем значение переменной BIN
set( BIN1 pileup )
set( BIN2 quality_marker )
# Имя проекта у нас соответствует имени программы.
project( "genome_analysis" )

# Устанавливаем корневой путь к папке с исходниками программы.
set( SOURCE_ROOT ${CMAKE_SOURCE_DIR}/src/ )
set( INCLUDE_ROOT ${CMAKE_SOURCE_DIR}/include/ )
set( LIB_ROOT ${CMAKE_SOURCE_DIR}/lib/ )

aux_source_directory( ${SOURCE_ROOT}/${BIN1}/ SOURCES1 )
aux_source_directory( ${SOURCE_ROOT}/${BIN2}/ SOURCES2 )

# Указываем пути, где искать заголовочники, дополнительно к стандартным путям.
include_directories( ${INCLUDE_ROOT} )

# Указываем пути, где искать сторонние динамически библиотеки. Эти пути будут
# просмотрены в дополнение к умолчальными системным путям.
link_directories( ${LIB_ROOT} )

# Перечисляем необходимые сторонние динамические библиотеки и сохраняем
# их список в переменной REQUIRED_LIBRARIES.
# Поиск этих библиотек будет произведён как по стандартным системным путям,
# так и по указанным выше (с помощью функции link_directories).
set( REQUIRED_LIBRARIES libbamtools.so )

# Устанавливаем флаги компилятора (причём никаких скрытых флагов, только эти).
set( CMAKE_CXX_FLAGS "-O0 -Wall -pedantic -std=c++0x" )

add_executable( ${BIN1} ${SOURCES1} )
add_executable( ${BIN2} ${SOURCES2} )

# Компонуем собранную программу с необходимыми динамическими библиотеками.
target_link_libraries( ${BIN1} ${REQUIRED_LIBRARIES} )
target_link_libraries( ${BIN2} )

