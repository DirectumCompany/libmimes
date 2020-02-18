# libmimes
## Описание
Библиотека libmimes предназначена для:
* определения MIME-типа файла;
* вычисления приложения-редактора, назначенного для определенного MIME-типа.

Исходный код собирается и в статическую, и в динамическую библиотеки.
## Сборка проекта
Для сборки проекта в системе должны быть установлены:
* cmake
* googletest

Для сборки проекта необходимо выполнить:
```shell script
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -- -j`nproc`
```