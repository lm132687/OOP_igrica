# OOP_Projekt
# Are You Human?
Lana Marinović i Gabriela Tošić - Igrica sa kratkom pričom, spot the difference, psihološki horror.

# Upute za igru
1. Igrica se igra klikom miša na objekte.
2. Igra zapoćinje klikom miša na pacijenta. Nastavak razgovora se odvija klikom miša.
3. Otvaranje menua za pregled simptoma, koristi se tipka E. Prelazak između stranica se izvodi tipkama strelica (lijevo, desno).
4. Na kraju razgovora potrebno je odabrati simptom za pregled te odlučiti sudbinu pacijenta.
5. Završetak igre ovisi o odlukama igrača.
 
# Kako pokrenuti projekt
1. Provjerite da imate instaliran C++17 ili noviji kompajler.
2. Instalirajte SFML 2.5+ (ili verziju koju projekt koristi).
   - Windows: možete koristiti prekompajliranu SFML biblioteku ili instalirati preko vcpkg.
   - Linux: "sudo apt install libsfml-dev"
3. Otvorite projekt u vašem IDE-u (Visual Studio ili Code::Blocks):
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./AreYouHuman
