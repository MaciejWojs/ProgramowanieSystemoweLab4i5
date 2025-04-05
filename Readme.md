# Laboratorium 4 i 5 - Sygnały w systemach operacyjnych

## Opis projektu
Repozytorium zawiera rozwiązania zadań z laboratorium 4 i 5 z Programowania Systemowego, których głównym celem była nauka obsługi sygnałów i komunikacji międzyprocesowej w języku C.

### Zakładka Releases
W sekcji "Releases" tego repozytorium znajdują się skompilowane wersje programów dla wszystkich poziomów optymalizacji (`O0`, `O1`, `O2`, `O3`). 

## Jak używać plików w języku C

1. **Kompilacja plików C**
   Aby skompilować plik w języku C, użyj polecenia `gcc`:
   ```bash
   gcc -o <nazwa_wyjściowego_pliku> <nazwa_pliku.c>
   ```
   Przykład:
   ```bash
   gcc -o 2.out 2.c
   ```
## Dostęp do zadań


2. **Uruchamianie programu**
   Po skompilowaniu pliku uruchom program za pomocą:
   ```bash
   ./<nazwa_wyjściowego_pliku>
   ```
   Przykład:
   ```bash
   ./2.out
   ```

3. **Obsługa sygnałów**
   - **SIGTERM**: Użyj polecenia `kill` z odpowiednim ID procesu:
     ```bash
     ps aux | grep .out
     kill <ID>
     ```
   - **SIGINT**: Naciśnij `Ctrl+C` w terminalu, w którym działa program.
   - **SIGHUP**: Wyślij sygnał za pomocą:
     ```bash
     kill -SIGHUP <ID>
     ```
   - **SIGUSR1/SIGUSR2**: W przypadku zadania 7, użyj:
     ```bash
     kill -s SIGUSR1 <ID>
     kill -s SIGUSR2 <ID>
     ```

## Lista zadań


### Zadanie 1
Program demonstracyjny pokazujący obsługę sygnału SIGINT (Ctrl+C). Program czeka w nieskończonej pętli na naciśnięcie Ctrl+C, a po otrzymaniu sygnału, wyświetla komunikat i kończy działanie.

```bash
# Kompilacja
gcc -o sygnaly sygnaly.c

# Uruchomienie
./sygnaly

# Obsługa SIGINT
# (naciśnij Ctrl+C w konsoli)
```

### Zadanie 2
Program demonstrujący obsługę podstawowych sygnałów (SIGTERM, SIGINT, SIGHUP).

```bash
# Uruchomienie programu
./2.out

# Obsługa SIGTERM
ps aux | grep .out
kill <ID>

# Obsługa SIGINT
./2.out
# (naciśnij Ctrl+C)

# Obsługa SIGHUP
./2.out
kill -SIGHUP <ID> 
```

### Zadanie 3
Program demonstracyjny pokazujący informacje o procesie (PID, PPID, UID, EUID).

```bash
# Kompilacja
gcc -o 3.out 3.c

# Uruchomienie
./3.out
```
### Zadanie 5
Program demonstrujący obsługę sygnałów oraz automatyczne wysyłanie sygnału SIGTERM do siebie, gdy wygeneruje liczbę podzielną przez 100.

```bash
# Kompilacja
gcc -o 5.out 5.c

# Uruchomienie
./5.out
```

### Zadanie 6
Program służący do wysyłania sygnału SIGINT do innego procesu o określonym PID.

```bash
# Kompilacja
gcc -o 6.out 6.c

# Uruchomienie
./6.out <PID>
```

### Zadanie 7
Program demonstracyjny wykorzystujący sygnały SIGUSR1 i SIGUSR2 do rysowania trójkątów za pomocą skryptu Python.

```bash
# Kompilacja programu C
gcc -o 7.out 7.c

# Ustawienie uprawnień do wykonywania dla skryptu Python
chmod +x trojkat.py

# Pierwszy terminal - uruchomienie programu
./7.out

# Drugi terminal - wysyłanie sygnałów
ps -u | grep 7.out
kill -s SIGUSR1 <ID>  # Rysuje trójkąt równoramienny
kill -s SIGUSR2 <ID>  # Rysuje trójkąt prostokątny
kill -s SIGINT <ID>   # Kończy działanie programu
```

## Skrypt wspierający - trojkat.py

Skrypt Python używany przez program 7.c do rysowania trójkątów:

- Uruchomienie z parametrem 1: rysuje trójkąt równoboczny
- Uruchomienie z parametrem 2: rysuje trójkąt prostokątny

Przykład użycia:
```bash
./trojkat.py 1  # Rysuje trójkąt równoboczny
./trojkat.py 2  # Rysuje trójkąt prostokątny
```

## Powiązane pliki

- `trojkat.py` - Skrypt pomocniczy do rysowania trójkątów
- `*.c` - Pliki źródłowe programów w języku C odpowiadające zadaniom