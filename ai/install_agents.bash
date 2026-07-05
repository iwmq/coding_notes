#!/bin/bash

/*
 * This script installs various AI coding agents globally using npm and bun.
 * It is intended to be run in a Unix-like environment with npm and bun installed.

 * NOTE: using npm is quicker in China than other curl-based installation methods.
 * All these agents are used for playing LLMs. No serious coding.
 */

npm install -g @anthropic-ai/claude-code
npm install -g codewhale
npm install -g @moonshot-ai/kimi-code
npm install -g opencode-ai
npm install -g --ignore-scripts @earendil-works/pi-coding-agent

bun install -g @oh-my-pi/pi-coding-agent