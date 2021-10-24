#!/user/bin/env bash
set -eu -o pipefail

BASE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SCRIPTS_DIR="$BASE_DIR/scripts"
PROJECT_DIR="$BASE_DIR/.."
