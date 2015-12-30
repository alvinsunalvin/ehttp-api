# ehttp-api
http libevent api service

# Dependencies

- libevent http://libevent.org/
- libcurl http://curl.haxx.se/
- hiredis https://github.com/redis/hiredis
- libevhtp https://github.com/ellzey/libevhtp
- cJSON https://github.com/kbranigan/cJSON http://cjson.sourceforge.net/
- libzdb https://github.com/mverbert/libzdb http://www.tildeslash.com/libzdb
- zlog http://hardysimpson.github.com/zlog/

# install guide

Except cJSON:

```
$ wget DPND
$ tar xf DPND.tar*
$ cd DPND
$ ./configure # Optional, if it has
$ make
$ sudo make install

# libevhtp 的特殊处理
由于内网的 http 服务,可以将 openssl 禁掉.
$ cd libevhtp-*
$ vim evhtp.h
加入以下内容:
#define EVHTP_DISABLE_SSL 1

安装成功后执行:
$ cd /usr/local/include/evhtp
$ sudo cp * ../

# libzdb 安装后的特殊处理
$ cd /usr/local/include/zdb
$ sudo cp * ../
```

# 注意事项

新 clone 的项目请依次执行以下的命令:

```
$ git submodule init
$ git submodule update
```
