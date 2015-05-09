![Logo](http://owl.dmtry.me/img/repository.png "Owl Framework")

## [Website](http://owl.dmtry.me/) :: [Documentation](http://docs.owl.dmtry.me/) :: [Get started](http://owl.dmtry.me/get-started)

[![Join the chat at https://gitter.im/owl-framework/owl](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/owl-framework/owl?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

[![Latest Stable Version](http://img.shields.io/packagist/v/owl/owl.svg?style=flat)](https://packagist.org/packages/owl/owl)
[![Author](http://img.shields.io/badge/author-@ovr-blue.svg?style=flat-square)](https://twitter.com/ovrweb)
[![Build Status](https://img.shields.io/travis/owl-framework/owl/master.svg?style=flat-square)](https://travis-ci.org/owl-framework/owl)
[![Software License](https://img.shields.io/badge/license-MIT-brightgreen.svg?style=flat-square)](LICENSE.md)

Owl is an extreme fast PHP framework powered by [Zephir](https://github.com/phalcon/zephir) language and delivered as C-extension.

*This is a development branch and We need to focus on the docs, tests, fixes and cleaning code, so we need your help ;)*

* Linux: [![Build Status](https://api.travis-ci.org/owl-framework/owl.svg?branch=master)](http://travis-ci.org/owl-framework/owl)
* Windows: [![Build status](https://ci.appveyor.com/api/projects/status/42x5t3f564jij2eh/branch/master?svg=true)](https://ci.appveyor.com/project/ovr/owl/branch/master)

### System Requirements

To build it you need the following requirements:

* `g++` >= 4.4/`clang++` >= 3.x or `vc++` >= 9 for Windows users
* `make` 3.81 or later
* `autoconf` 2.31 or later
* `automake` 1.14 or later
* PHP development headers and tools

If you're using Ubuntu, you can install the required packages this way:

```bash
sudo apt-get update
sudo apt-get install git gcc make re2c php5-cli php5-json php5-dev libpcre3-dev
```

### Installation

You can build extension and install it like:

```bash
git clone https://github.com/owl-framework/owl.git
cd ext
./install
```

Enable extension for all SAPIs:

```sh
sudo echo extension=owl.so > /etc/php5/mods-available/owl.ini
sudo php5enmod owl
```

Don't forget to restart your php-fpm:

```bash
sudo service php5-fpm restart
```

### Build Zephir code

To build the zep Source to C extension:
* [zephir](https://github.com/phalcon/zephir)

### Contributing

1. Fork the current repository by fork button.
2. Create a new branch for each feature or improvement. `git checkout -b my-branch`
3. Send a pull request from each feature branch to the master branch.

*Please do not send files from `/ext` directory, just those from the `/owl`.

### Components

- Annotations
- Cache
- Bridge
- Event
- Log
- Session
- Mvc
    * Controller
- Http
    * Request
    * Response
- Application

License
-------

This project is open-sourced software licensed under the MIT License. See the LICENSE file for more information.
