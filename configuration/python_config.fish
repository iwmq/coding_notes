# file: ~/.config/fish/conf.d/python_config.fish
# This is configuration for using pyenv in fish shell

# See https://github.com/pyenv/pyenv
# Setup pyenv and pyenv-virtualenv
pyenv init - fish | source
pyenv virtualenv-init - fish | source

# See https://virtualfish.readthedocs.io/en/latest/install.html
# Use uv to install virtualfish, and add virtualenv name to prompt
# NOTE: `vf install` only runs once
# NOTE: set EDITOR to vim before run `funced fish_prompt`
