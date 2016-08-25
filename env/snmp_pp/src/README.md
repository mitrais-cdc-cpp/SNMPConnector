# SNMP++ Source (modified)

There is something need to be modified from SNMP++ source.
So, please use this source (snmp++-3.3.7.tar.gz) because it has been modified to could compile and install into our linux environment. 

Prequisite :

Install C++ compiler for multi library. 

**sudo apt-get install gcc-multilib g++-multilib**

**sudo apt-get install autoconf** (if autoconf does not installed yet)

Steps to compile and install:
1. autoreconf -i
2. ./configure
3. make
4. sudo make install

The SNMP++ will be installed into your machine.
