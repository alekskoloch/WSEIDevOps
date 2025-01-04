# Wybierz bazowy obraz Ubuntu
FROM ubuntu:latest

# Ustaw zmienną środowiskową dla nieinteraktywnej instalacji
ENV DEBIAN_FRONTEND=noninteractive

# Zainstaluj niezbędne pakiety
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
        git \
        wget \
        unzip \
        && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Ustaw katalog roboczy
WORKDIR /app

# Skopiuj pliki projektu do obrazu
COPY . .

# Utwórz katalog build i skompiluj projekt
RUN cmake -S . -B build && \
    cmake --build build

# Ustaw domyślny punkt wejścia
CMD ["./build/WSEIDevOps"]