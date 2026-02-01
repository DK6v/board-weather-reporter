PLANTUML = plantuml
SOURCES = $(wildcard *.puml)
PNG_FILES = $(SOURCES:.puml=.png)

all: $(PNG_FILES)

%.png: %.puml
	$(PLANTUML) $< -tpng

clean:
	rm -f *.png

.PHONY: all clean