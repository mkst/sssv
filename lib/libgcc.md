# libgcc.a

This `libgcc.a` was compiled using GCC 12.4 using GCC 12.4 sources.

Instructions below (performed in an Ubuntu 22.04 Docker container).

```bash
docker run --rm -t -v $(pwd)/gcc:/gcc ubuntu:22.04 bash
```

Inside the container:

```bash
apt update

apt install -y \
    wget \
    build-essential \
    gcc-mips-linux-gnu \
    flex bison texinfo \
    libgmp-dev libmpfr-dev libmpc-dev \
    zlib1g-dev

wget https://ftp.gnu.org/gnu/gcc/gcc-12.4.0/gcc-12.4.0.tar.gz

tar xvf gcc-12.4.0.tar.gz

cd gcc-12.4.0/

mkdir build

cd build

../configure \
    --target=mips-linux-gnu \
    --enable-languages=c \
    --disable-libatomic \
    --disable-libgcc-pic \
    --disable-libgcc-pic \
    --disable-libgomp \
    --disable-libquadmath \
    --disable-libssp \
    --disable-libstdcxx-pch \
    --disable-multilib \
    --disable-nls \
    --disable-shared \
    --disable-threads \
    --without-headers \
    --with-newlib \
    --with-gnu-as \
    --with-gnu-ld \
    --with-as=/usr/bin/mips-linux-gnu-as \
    --with-ld=/usr/bin/mips-linux-gnu-ld \
    CFLAGS_FOR_TARGET="-mips3 -mabi=32 -mno-abicalls -fno-pic -G0"

make -j$(nproc) all-gcc

sed -i mips-linux-gnu/libgcc/Makefile s'/PICFLAG = .*/PICFLAG =/'

make -j$(nproc) all-target-libgcc
```

Trim down the archive to just the objects we need:

```bash
mips-linux-gnu-ar x   ./mips-linux-gnu/libgcc/libgcc.a _floatdisf.o _fixsfdi.o _fixunssfdi.o
mips-linux-gnu-ar rcs /gcc/libgcc.a _floatdisf.o _fixsfdi.o _fixunssfdi.o
```

Custom lines in the `sssv.ld`:

```ld
    .libgcc :
    {
        build/lib/libgcc.a:_fixsfdi.o(.text .rodata .rodata.* .data);
        build/lib/libgcc.a:_floatdisf.o(.text .rodata .rodata.* .data);
        build/lib/libgcc.a:_fixunssfdi.o(.text .rodata .rodata.* .data);
    }
```
