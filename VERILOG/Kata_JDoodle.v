module jdoodle;
    parameter integer A = 25; // Задаем число как параметр

    initial begin
        $display("Десятичное: %d", A);
        $display("Двоичное: %b", A);
        $display("Троичное: %0d", to_ternary(A)); // Функция перевода в троичную систему
        $finish;
    end

    function integer to_ternary;
        input integer num;
        integer result, place;
        begin
            result = 0;
            place = 1;
            while (num > 0) begin
                result = result + (num % 3) * place;
                num = num / 3;
                place = place * 10;
            end
            to_ternary = result;
        end
    endfunction
endmodule
