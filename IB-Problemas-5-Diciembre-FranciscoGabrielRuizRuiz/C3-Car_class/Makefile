SHELL := /bin/bash
TARGET = car_class-c3
CXX= g++
CXXFLAGS= -Wall -std=c++17 -o $(TARGET)

files = ./*.cc

BOLD := $(shell tput bold)
CLEAR := $(shell tput clear)

all: $(TARGET)

$(TARGET): $(files)
	@$(CXX) $(CXXFLAGS) $(files)


.PHONY: clean
clean:
	@rm $(TARGET)


.PHONY: help
help:
	@echo "${BOLD}make${CLEAR} -> compile"
	@echo "${BOLD}make clean${CLEAR} -> remove binary"