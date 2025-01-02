#include <LiquidCrystal.h>
#include <DHT.h>

// Pin definitions
#define DHTPIN 8       // Pin where the DHT11 is connected
#define DHTTYPE DHT11  // DHT 11 sensor type

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize the LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  // Start LCD and DHT
  lcd.begin(16, 2); // Set up LCD as 16x2
  dht.begin();

  // Display initializing message
  lcd.print("Initializing...");
  delay(2000); // Pause for 2 seconds
}

void loop() {
  // Read data from DHT11
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if the readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0); // Set cursor to the first row
    lcd.print("Error Reading!  "); // Print error message
    delay(2000);
    return;
  }

  // Display temperature
  lcd.setCursor(0, 0); // Set cursor to the first row
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C  "); // Ensure to clear trailing characters

  // Display humidity
  lcd.setCursor(0, 1); // Set cursor to the second row
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %   "); // Ensure to clear trailing characters

  delay(2000); // Refresh data every 2 seconds
}
