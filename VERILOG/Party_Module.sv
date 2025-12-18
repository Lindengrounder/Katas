// 🎉 Party Module v1.337 - Let's Get This Silicon Rave Started! 💃🕺
module DiscoInferno (
    // 🌈 Cosmic Rhythm Generators
    input clkDiscoMaster,          // Main beat generator (50MHz glow stick)
    input [1:0] partyButtons,      // [0]: Dance floor reset, [1]: Unused (airhorn button?)
    
    // 💡 Light Show Apparatus
    output reg [7:0] danceFloor,   // Main LED rave array (active-low glow)
    
    // 🌐 Internet Telepathy Portals
    input dataGrooveIn,            // RX Clock (incoming funk)
    input netRxGrooveValid,        // RX Data Valid (nodding to the beat)
    input netRxOops,               // RX Error (record scratch)
    input [3:0] netRxData,         // RX Data (the secret sauce)
    
    output reg netTxGrooveEnable,  // TX Enable (throwin' shapes)
    output reg [3:0] netTxData,    // TX Data (sharing the groove)
    input dataGrooveOut,           // TX Clock (outgoing funk)
    
    // 🤖 Robotic Dance Instructors
    output reg mdioConductor,      // MDIO Clock (dance tempo)
    inout mdioDancePartner,        // MDIO Data (partner's moves)
    
    // 🛡 Shield Light Orchestra
    output reg discoBallA_Ok,      // Active-low confirmation boogie
    output reg discoBallB_Ok,      // Active-low backup dancer status
    output reg discoBallA_Oops,    // Active-low "I stepped on your foot"
    output reg discoBallB_Oops,    // Active-low "My shoes are glowing?"
    output reg [2:0] laserShow,    // Active-low optical extravaganza
    
    // 🔘 Shield Interaction Devices
    input [1:0] secretSauceButtons,  // Mysterious flavor enhancers
    input panicButton,               // The big red "oh funk" button
    input [11:0] secretSauceDials,   // Grandma's recipe switches
    
    // 📡 Mysterious Vanishing Bytes (MVB)
    output reg mvbDiscoStrobeA,    // MVB A: Enable glitter cannon
    output reg mvbDiscoStreamA,    // MVB A: Sequence of sweet moves
    input mvbDiscoEchoA,           // MVB A: Return of the mac(arena)
    
    output reg mvbDiscoStrobeB,    // MVB B: Backup glitter cannon
    output reg mvbDiscoStreamB,    // MVB B: Alternate dance routine
    input mvbDiscoEchoB,           // MVB B: Echo location (maraca edition)
    
    // 🎛 General Purpose Fun Port
    output reg [9:0] magicSparkles  // Generic pixie dust output
);

    // 💫 Internal Rave Generators
    reg beatGenerator = 0;       // PLL-derived dance rhythm (75MHz hustle)
    reg beatLocked = 0;          // PLL stability flag (1 = dance approved)
    reg [7:0] lightChoreography = 0;  // LED dance routine memory
    reg metronome1ms = 0;        // Precision timing for robot dancers

    // 🎤 Initial Announcement
    initial begin
        $display("🎶🎶🎶 INITIATING DISCO INFERNO PROTOCOL 🎶🎶🎶");
        $display("🔦 Clap lights: %b", clkDiscoMaster);
        $display("🔘 Secret handshake: %b", secretSauceDials);
        $display("📡 MVB telepathy status: A=%b B=%b", 
                mvbDiscoEchoA, mvbDiscoEchoB);
        $display("💡 Let there be rave light!");
    end

    // 🕺 PLL Dance Floor Preparation
    always #10 beatGenerator = ~beatGenerator;  // 75MHz rhythm generation
    initial begin
        #50 beatLocked = 1;  // Let the beat drop!
        $display("🕒 PLL Locked at %t! The rhythm is gonna get you! ⏰", $time);
    end

    // 🎛 Main Dance Routine
    always @(posedge beatGenerator) begin
        // 🔄 Reset Handling (When the bouncer shows up)
        if (partyButtons[0] && !panicButton) begin
            $display("🙅♂️ RESETTING DANCE FLOOR! 🙅♀️");
            lightChoreography <= 8'b0;
        end else begin
            // 🌈 LED Light Choreography
            lightChoreography <= lightChoreography + 1;
            danceFloor <= ~lightChoreography;  // Active-low glow inversion
            $display("💡 Light pattern 0x%h: %b (%0t)", 
                    lightChoreography, danceFloor, $time);
            
            // Create light wave pattern instead of simple increment
            if (&lightChoreography[6:1])  // Special effect when middle bits are 1
                danceFloor <= ~{lightChoreography[0], lightChoreography[7:1]};
        end

        // 📡 MVB Disco Transmission
        mvbDiscoStreamA <= ^lightChoreography[3:0];  // XOR pattern for fun
        mvbDiscoStreamB <= ^lightChoreography[7:4];
        mvbDiscoStrobeA <= 1;
        mvbDiscoStrobeB <= 1;
        $display("📡 MVB transmitting funky bits: A=%b B=%b ⏲%t",
                mvbDiscoStreamA, mvbDiscoStreamB, $time);

        // 🌐 Ethernet Echo Chamber
        netTxGrooveEnable <= 1;
        netTxData <= netRxData;  // Parrot the received funk
        $display("🔄 Ethernet echoing 0x%h at %t", netTxData, $time);

        // 🛡 Shield Light Show
        discoBallA_Ok <= ~lightChoreography[7];
        discoBallB_Ok <= ~lightChoreography[6];
        discoBallA_Oops <= lightChoreography[5];
        discoBallB_Oops <= lightChoreography[4];
        laserShow <= {~lightChoreography[3], ~lightChoreography[2], ~lightChoreography[1]};
        $display("✨ Shield LEDs doing the electric slide! ⚡%t", $time);
    end

    // ⏱ Precision Dance Timing
    always #1000 metronome1ms = ~metronome1ms;  // 1ms timing heartbeat
    always @(posedge metronome1ms) begin
        $display("⏱ Another millisecond of pure silicon joy! (%t)", $time);
        if ($random % 100 < 5) begin  // 5% chance of surprise message
            $display("🎉 Party tip: Always drive active-low signals with ❤️");
        end
    end

    // 🎁 Hidden Easter Egg: Light show when secret combo pressed
    always @(posedge beatGenerator) begin
        if (secretSauceDials == 12'hACE && secretSauceButtons == 2'b11) begin
            danceFloor <= ~{8{beatGenerator}};  // Blink all LEDs to beat
            $display("🎊 SECRET COMBO ACTIVATED! UNLEASHING FULL DISCO POWER! 🎊");
        end
    end

endmodule
