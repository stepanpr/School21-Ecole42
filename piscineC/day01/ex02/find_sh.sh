find . -name "*.sh" | rev | tr "/" "." |  cut -d . -f 2 | rev
