#!/user/bin/env bash
set -eu -o pipefail

BASE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${BASE_DIR}/../config.sh"

if [ -z "${1:-}" ]; then
    printf "Usage: ${0} contests/abc086/D \n"
    exit 1
fi

TASK="${1}"
TASK_DIR="${PROJECT_DIR}/${TASK}"

submit() {
    printf "Submit ${TASK}... \n"
    cd "${TASK_DIR}"
    atcoder-tools submit -u
}

main() {
    submit
}

main
