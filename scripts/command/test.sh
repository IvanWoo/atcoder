#!/user/bin/env bash
set -eu -o pipefail

BASE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source "${BASE_DIR}/../config.sh"

if [ -z "${1:-}" ]; then
  printf "Usage: ${0} contests/abc086/D \n"
  exit 1
fi

TASK="${1}"
TASK_DIR="${PROJECT_DIR}/${TASK}"

build () {
    printf "Build ${TASK}... \n"
    gcc-9 -std=gnu++17 -g -Wall -lstdc++ -Wunused-result "${TASK_DIR}/main.cpp" -o "${TASK_DIR}/main"
}

test () {
    printf "Test ${TASK}... \n"
    atcoder-tools test -d "${TASK_DIR}"
}

main () {
    build
    test
}

main