#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Hf {
    double spread_mean;
    double leverage;
    int size;
    double num_param;
    char symbol_a[10];
    char symbol_b[10];
};

double get_symbol_price(char* symbol) {
    // Simulate fetching the symbol price (replace with actual implementation)
    return 100.0;
}

void execute_trade(char* symbol, char* side, double leverage, int qty, double price) {
    // Simulate executing a trade (replace with actual implementation)
    printf("%s %s, order executed\n", side, symbol);
}

void perform_trade_logic(struct Hf* hf, double spread) {
    // Simulate performing trade logic (replace with actual implementation)
    // ...

    // Example logic:
    if (spread < (hf->spread_mean - hf->num_param)) {
        execute_trade(hf->symbol_a, "buy", hf->leverage, hf->size, get_symbol_price(hf->symbol_a) + 1);
        execute_trade(hf->symbol_b, "sell", hf->leverage, hf->size, get_symbol_price(hf->symbol_b) - 1);
    } else if (spread > (hf->spread_mean + hf->num_param)) {
        execute_trade(hf->symbol_a, "sell", hf->leverage, hf->size, get_symbol_price(hf->symbol_a) - 1);
        execute_trade(hf->symbol_b, "buy", hf->leverage, hf->size, get_symbol_price(hf->symbol_b) + 1);
    }
    // ...
}

void run_strategy(struct Hf* hf) {
    while (1) {
        // Get ticker prices of symbols
        double price_a = get_symbol_price(hf->symbol_a);
        double price_b = get_symbol_price(hf->symbol_b);

        // Calculate the spread
        double spread = price_a - price_b;
        printf("Spread = %f\n", spread);

        // Perform trading logic based on the spread
        perform_trade_logic(hf, spread);

        // Simulate waiting for 60 seconds
        sleep(60);
    }
}

int main() {
    struct Hf hf;
    hf.spread_mean = 2.0;
    hf.leverage = 1.5;
    hf.size = 10;
    hf.num_param = 0.5;
    strcpy(hf.symbol_a, "BTCUSD");
    strcpy(hf.symbol_b, "ETHUSD");

    run_strategy(&hf);

    return 0;
}
