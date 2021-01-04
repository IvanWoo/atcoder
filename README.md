# AtCoder

## Requirements

- gcc 9
- pipenv

## Setup

```sh
$ pipenv install
$ pipenv shell
```

## Usage

New contest

```sh
$ atcoder-tools gen {contest_id} --without-login --workspace ./contests/ --config ./config/atcodertools.toml
```

```sh
$ pipenv run at-gen {contest_id}
```

Compile single task

```sh
$ gcc-9 -std=gnu++17 -g -Wall -lstdc++ -Wunused-result ./contests/agc001/A/main.cpp -o ./contests/agc001/A/main
```

Test single task

```sh
$ atcoder-tools test -d ./agc001/A
```
