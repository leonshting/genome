cmake_minimum_required( VERSION 2.6 )

# Устанавливаем значение переменной BIN
set( BIN first )
# Имя проекта у нас соответствует имени программы.
project( ${BIN} )

# Устанавливаем корневой путь к папке с исходниками программы.
set( SOURCE_ROOT ../src/ )

aux_source_directory( ${SOURCE_ROOT} SOURCES )

# Указываем пути, где искать заголовочники, дополнительно к стандартным путям.
include_directories( "/usr/local/include/bamtools/" )
include_directories( "../include/" )

# Устанавливаем путь, куда будет скопирован исполняемый файл при выполнении
# команды 'make install'.
set( INSTALL_PATH /usr/local/bin/ )

# Указываем пути, где искать сторонние динамически библиотеки. Эти пути будут
# просмотрены в дополнение к умолчальными системным путям.
link_directories( "/usr/local/lib/bamtools/" )

# Перечисляем необходимые сторонние динамические библиотеки и сохраняем
# их список в переменной REQUIRED_LIBRARIES.
# Поиск этих библиотек будет произведён как по стандартным системным путям,
# так и по указанным выше (с помощью функции link_directories).
set( REQUIRED_LIBRARIES libbamtools.so )

# Устанавливаем флаги компилятора (причём никаких скрытых флагов, только эти).
set( CMAKE_CXX_FLAGS "-O0 -Wall -pedantic -std=c++0x" )

add_executable( ${BIN} ${SOURCES} )
# Компонуем собранную программу с необходимыми динамическими библиотеками.
target_link_libraries( ${BIN} ${REQUIRED_LIBRARIES} )

# Установка. Это действие будет активировано при выполнении команды 'make install'.
install( TARGETS ${BIN} DESTINATION ${INSTALL_PATH} )
