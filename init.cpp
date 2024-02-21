// Include custom headers
#include "object.cpp"

Object debug = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

#pragma region Group Backdrop
// Group Backdrop
Object backdrop = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
void renderBackdrop()
{
    // Backdrop abstract
    glColor4f(COLOR_GREEN_1);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.5, 100, -40, 158);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.1, 40, 170, 290);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 3.5, 800, 0, 360);

    glColor4f(COLOR_RED_1);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.8, 150, 200, 45);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.4, 80, 50, 140);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 2.1, 20, 0, 360);
    glColor4f(COLOR_GREEN_1);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.7, 80, 245, 0);

    // Watch Glow
    glColor4f(COLOR_WHITE_1);
    for (int i = WATCH_BODY_RADIUS; i <= WATCH_BODY_RADIUS + 200; i += 40)
        backdrop.drawCircle(i, 0, 360);
}
#pragma endregion Group Backdrop

#pragma region Group Watch Body
Object watchBody = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watchStrap = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watchButton = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
void renderWatchBody()
{
    // Watch Button 1
    glColor4f(COLOR_GREY);
    watchButton.drawCircle(WATCH_BODY_RADIUS + 30, 50, 80);
    for (int i = WATCH_BODY_RADIUS; i <= WATCH_BODY_RADIUS + 25; i++)
    {
        // watchButton.drawCircle(i, 50, 80);
    }
    glColor4f(COLOR_RED_DARK);
    watchButton.drawCircle(WATCH_BODY_RADIUS + 20, 50, 80);
    // glColor4f(COLOR_BLACK_2);
    // watchButton.drawCircle(WATCH_BODY_RADIUS + 15, 40, 80);
    // watchButton.drawCircle(WATCH_BODY_RADIUS + 15, 40, 80);

    // Watch button 2
    glColor4f(COLOR_GREY);
    watchButton.drawCircle(WATCH_BODY_RADIUS + 30, 110, 140);

    // Watch Body
    glColor4f(COLOR_WHITE);
    watchBody.drawCircle(WATCH_BODY_RADIUS, 0, 360);

    glColor4f(COLOR_BLACK_2);
    for (int i = WATCH_BODY_RADIUS; i >= BACKGROUND_CIRCLE_RADIUS; i--)
    {
        watchBody.drawCircle(i, 0, 360);
    }
    glColor4f(COLOR_BLACK);

    // After the watch body
    watchBody.drawTorus(WATCH_BODY_RADIUS, 20, 0, 360);

    // After the background circle
    watchBody.drawTorus(BACKGROUND_CIRCLE_RADIUS, 25, 0, 360);

    // Add body highlight
    glColor4f(COLOR_WHITE);
    watchBody.drawTorus(WATCH_BODY_RADIUS + 3, 2, 0, 360);
}

void rederWatchStrap()
{
    // Watch Strap
    glColor4f(COLOR_GREEN_DARK);
    watchStrap.drawRoundedRectFill(BACKGROUND_CIRCLE_RADIUS, WINDOWS_HEIGHT, 10);

    // Center Red
    glColor4f(COLOR_RED_DARK);
    watchStrap.translate(50, 0);
    watchStrap.drawRoundedRectFill(BACKGROUND_CIRCLE_RADIUS / 2, WINDOWS_HEIGHT, 10);

    // Side
    glColor4f(COLOR_WHITE);
    watchStrap.translate(-170, 0);
    watchStrap.drawRoundedRectFill(10, WINDOWS_HEIGHT, 0);

    glColor4f(COLOR_RED);
    watchStrap.translate(-30, 0);
    watchStrap.drawRoundedRectFill(10, WINDOWS_HEIGHT, 0);

    // Holes
    glColor4f(COLOR_BLACK);
    watchStrap.x = WINDOWS_CENTER_X;
    watchStrap.y = WINDOWS_CENTER_Y + WINDOWS_HEIGHT / 2 - 50;
    for (int i = 0; i < 2; i++)
    {

        watchStrap.drawRoundedRectFill(STRAP_HOLE_WIDTH, STRAP_HOLE_HEIGHT, STRAP_HOLE_CORNER_RADIUS);
        watchStrap.translate(0, -150);
    }
}
#pragma endregion Group Watch Body

#pragma region Group Background
Object background = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object seconds = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object outerRing = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

Object watermelonShellA = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonShellB = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonFleshA = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonFleshB = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonSeedA = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonSeedB = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderBackground()
{
    glColor4f(COLOR_GREEN_LIGHT);
    background.drawCircle(BACKGROUND_CIRCLE_RADIUS, 0, 360);
    // Seconds
    glColor4f(COLOR_RED);
    seconds.drawTorus(SECONDS_RING_RADIUS, SECONDS_RING_THICKNESS, 0, 194);

    // Outer Ring
    glColor4f(COLOR_GREEN);
    outerRing.drawTorus(OUTER_RING_RADIUS, OUTER_RING_THICKNESS, 0, 360);

    glColor4f(COLOR_WHITE_1);
    int stepA = OUTER_RING_RADIUS - (OUTER_RING_THICKNESS / 2);
    for (int i = OUTER_RING_RADIUS; i >= stepA; i--)
    {
        for (int j = 1; j <= (OUTER_RING_RADIUS - i + 1); j++)
        {
            outerRing.drawTorus(i, 1, 0, 360);
        }
    }
}

void renderWatermelon()
{
    // Watermelon Shell
    const int shellThicknessA = 15;
    const int shellThicknessB = 40;

    const int watermelonARadius = 140;
    const int watermelonAOffsetX = -150;
    const int watermelonAOffsetY = -150;
    const int watermelonARotation = 50; // Default straight up
    const int watermelonASeedOffsetX = -180;
    const int watermelonASeedOffsetY = -180;

    const int watermelonBRadius = 450;
    const int watermelonBOffsetX = 10;
    const int watermelonBOffsetY = 350;
    const int watermelonBRotation = -10; // Default straight up
    const int watermelonBSeedOffsetX = -180;
    const int watermelonBSeedOffsetY = -180;

    const int watermelonSeedABottomRadius = 5;
    const int watermelonSeedATopRadius = 2;
    const int watermelonSeedALength = 9;
    const int watermelonSeedBBottomRadius = 8;
    const int watermelonSeedBTopRadius = 3;
    const int watermelonSeedBLength = 16;

    glColor4f(COLOR_GREEN_1); // Set color to transparently green
    watermelonShellA.translate(watermelonAOffsetX, watermelonAOffsetY);
    watermelonShellA.drawTorus(watermelonARadius, shellThicknessA, 90 + watermelonARotation, 270 + watermelonARotation);
    watermelonShellB.translate(watermelonBOffsetX, watermelonBOffsetY);
    watermelonShellB.drawTorus(watermelonBRadius, shellThicknessB, 130 + watermelonBRotation, 200 + watermelonBRotation);

    // Watermelon Flesh
    glColor4f(COLOR_RED_1);
    watermelonFleshA.translate(watermelonAOffsetX, watermelonAOffsetY);
    watermelonFleshA.drawCircle(watermelonARadius - shellThicknessA, 90 + watermelonARotation, 270 + watermelonARotation);

    watermelonFleshB.translate(watermelonBOffsetX, watermelonBOffsetY);
    watermelonFleshB.drawCircle(watermelonBRadius - shellThicknessB, 130 + watermelonBRotation, 200 + watermelonBRotation);

    // Watermelon Seed
    glColor4f(COLOR_BLACK_2);
    watermelonSeedA.translate(watermelonAOffsetX, watermelonAOffsetY);
    watermelonSeedA.translate(-30, -26);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 45);
    watermelonSeedA.translate(82, -54);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, -18);
    watermelonSeedA.translate(-40, -34);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 15);
    watermelonSeedA.translate(-28, 40);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 35);
    watermelonSeedA.translate(-40, -12);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 28);
    watermelonSeedA.translate(-38, 42);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 58);
    watermelonSeedA.translate(20, 49);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 78);
    watermelonSeedA.translate(-10, 40);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 95);

    watermelonSeedB.translate(watermelonBOffsetX, watermelonBOffsetY);
    watermelonSeedB.translate(26, -40);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -30);
    watermelonSeedB.translate(62, -40);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -59);
    watermelonSeedB.translate(-80, -40);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, 12);
    watermelonSeedB.translate(66, -26);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -23);
    watermelonSeedB.translate(106, -13);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -44);
    watermelonSeedB.translate(-53, -48);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -14);

    watermelonSeedB.translate(145, -4);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -74);
    watermelonSeedB.translate(-56, -40);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -54);
    watermelonSeedB.translate(-30, -63);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -34);
}

#pragma endregion Group Background

#pragma region Group Center Piece
// Group Center Piece
Object coreCircle = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object minutes = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object analogQuaterIndicator = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object analogIndicator = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textAMPM = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textMinute = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderCenterPiece()
{
    // =============================================== Group Center Piece
    // Core Red Circle
    glColor4f(COLOR_RED);
    coreCircle.drawCircle(CORE_CIRCLE_RADIUS, 0, 360);
    // Minutes Circle
    glColor4f(COLOR_GREEN);
    minutes.drawCircle(MINUTES_CIRCLE_RADIUS, 0, 288);
    glColor4f(COLOR_WHITE_2);
    minutes.drawTorus(MINUTES_CIRCLE_RADIUS - 20, 5, 0, 288);

    // -- Analog Indicator
    glColor4f(COLOR_BLACK);

    for (int i = 90; i <= 360; i += 90)
    {
        analogQuaterIndicator.drawTorus(
            MINUTES_CIRCLE_RADIUS - ANALOG_QUATER_INDICATOR_LENGTH / 2,
            ANALOG_QUATER_INDICATOR_LENGTH,
            i - ANALOG_INDICATOR_WIDTH,
            i + ANALOG_INDICATOR_WIDTH);
    }

    for (int i = 30; i <= 330; i += 30)
    {
        if (i == 90 || i == 180 || i == 270 || i == 360)
        {
            continue;
        }
        analogIndicator.drawTorus(
            CORE_CIRCLE_RADIUS - ANALOG_INDICATOR_LENGTH / 2,
            ANALOG_INDICATOR_LENGTH,
            i - ANALOG_INDICATOR_WIDTH,
            i + ANALOG_INDICATOR_WIDTH);
    }
    // Minute label
    glColor4f(COLOR_WHITE);
    textMinute.translate(-105, -45);
    textMinute.drawText("48", 10);

    textAMPM.translate(-30, -100);
    textAMPM.scale(0.30);
    textAMPM.drawText("AM", 2);
    // =============================================== Group Center Piece
}
#pragma endregion Group Center Piece

#pragma region Group Hour
// Group Hour
Object hourCircle = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object hourPointer = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textHour = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderHour()
{
    // =============================================== Group Hour
    int current_Hour = 8;

    // Hour pointer
    glColor4f(COLOR_RED);
    hourPointer.drawTorus(OUTER_RING_RADIUS * .90, 15, 240, 264);

    // Hour circle
    hourCircle.translate(0, OUTER_RING_RADIUS * .90);
    for (int i = 0; i <= 360; i += 30)
    {

        hourCircle.rotate(i, WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
        if (i == current_Hour * 30)
        {
            glColor4f(COLOR_RED);
            hourCircle.drawCircle(50, 0, 360);
        }
        else
        {
            glColor4f(COLOR_BLACK);
            hourCircle.drawCircle(10, 0, 360);
        }
    }

    // Hour text
    glColor4f(COLOR_WHITE);
    textHour.translate(-401, -239);
    textHour.scale(0.50);
    textHour.drawText("8", 10);
    // =============================================== Group Hour
}
#pragma endregion Group Hour

#pragma region Group == == == == Complication

#pragma region Group Date and Day
// Group Date and Day
Object dayBox = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object dateBox = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textDate = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textDay = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderDateDay()
{
    // =============================================== Group Date and Day
    dayBox.translate(COMPLICATION_RING_RADIUS, -20);
    glColor4f(COLOR_RED);
    dayBox.drawRoundedRectFill(DAY_BOX_WIDTH, DAY_BOX_HEIGHT, DAY_BOX_CORNER_RADIUS);

    glColor4f(COLOR_GREEN);
    dateBox.translate(COMPLICATION_RING_RADIUS, 20);
    dateBox.drawRoundedRectFill(DATE_BOX_WIDTH, DATE_BOX_HEIGHT, DATE_BOX_CORNER_RADIUS);

    glColor4f(COLOR_WHITE);
    textDate.translate(COMPLICATION_RING_RADIUS - 80, 10);
    textDate.scale(0.25);
    textDate.drawText("12|Feb", 4);

    textDay.translate(COMPLICATION_RING_RADIUS - 25, -40);
    textDay.scale(0.15);
    textDay.drawText("Thu", 3);
    // =============================================== Group Date and Day
}
#pragma endregion Group Date and Day

#pragma region Group Heart
// Group Heart
Object iconHeart = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textHeartRate = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderHeart()
{
    // =============================================== Group Heart
    glColor4f(COLOR_RED);
    iconHeart.translate(-90, COMPLICATION_RING_RADIUS);
    iconHeart.drawHeart(20);

    glColor4f(COLOR_GREY);
    textHeartRate.translate(-50, COMPLICATION_RING_RADIUS - 10);
    textHeartRate.scale(0.25);
    textHeartRate.drawText("76bpm", 4);
    // =============================================== Group Heart
}
#pragma endregion Group Heart

#pragma region Group Battery
// Group Battery
Object iconBattery = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textBattery = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderBattery()
{
    // =============================================== Group Battery
    textBattery.translate(-10, -COMPLICATION_RING_RADIUS - 15);
    textBattery.scale(0.25);
    textBattery.drawText("60%", 4);

    glColor4f(COLOR_BLACK);
    iconBattery.translate(-35, -COMPLICATION_RING_RADIUS);
    // iconBattery.scale(0.2);
    iconBattery.drawBattery(20, 2, 1, 60);
    // =============================================== Group Battery
}
#pragma endregion Group Battery

#pragma region Group Step
// Group Step
Object textStepCount = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textStepUnit = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderStep()
{
    glColor4f(COLOR_GREY);
    textStepCount.translate(-COMPLICATION_RING_RADIUS - 50, 0);
    textStepCount.scale(0.35);
    textStepCount.drawText("4896", 6);

    glColor4f(COLOR_RED);
    textStepUnit.translate(-COMPLICATION_RING_RADIUS - 4, -28);
    textStepUnit.scale(0.15);
    textStepUnit.drawText("Step", 3);
}
#pragma endregion Group Step

void renderComplication()
{
    renderDateDay();
    renderHeart();
    renderBattery();
    renderStep();
}
#pragma endregion Group == == == == Complication

#pragma region Group Watch Glass
// Group Watch Glass
Object watchGlass = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderWatchGlass()
{
    // Watch Glass
    glColor4f(COLOR_BLACK_1);
    watchGlass.drawCircle(BACKGROUND_CIRCLE_RADIUS, 0, 360);

    // Shaddow
    int lowerBound = BACKGROUND_CIRCLE_RADIUS - 120;
    int upperBound = BACKGROUND_CIRCLE_RADIUS;
    int step = upperBound - lowerBound;
    for (int i = upperBound; i >= lowerBound; i--)
    {
        for (int j = lowerBound; j <= i; j++)
            watchGlass.drawTorus(i, 1, 0, 360);
    }

    // Reflect element on glass
    glColor4f(COLOR_WHITE_2);
    watchGlass.drawTorus(BACKGROUND_CIRCLE_RADIUS - 65, 85, 90, 160);
    watchGlass.drawTorus(BACKGROUND_CIRCLE_RADIUS - 95, 45, 100, 180);
    watchGlass.drawTorus(BACKGROUND_CIRCLE_RADIUS - 65, 60, 290, 338);
    watchGlass.drawTorus(BACKGROUND_CIRCLE_RADIUS - 70, 25, 300, 350);
}
#pragma endregion Group Watch Glass

#pragma region Group Vignnette Filter
// Group Vignnette Filter
Object vignetteFilter = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
void renderVignetteFilter()
{
    // Vignette Filter
    glColor4f(COLOR_BLACK_VIG);
    int initialRadius = WINDOWS_WIDTH;
    int initialWidth = 1600;
    vignetteFilter.drawTorus(initialRadius, initialWidth, 0, 360);
    for (int i = 0; i <= 220; i++)
    {
        vignetteFilter.drawTorus(initialRadius, initialWidth, 0, 360);
        initialWidth -= 30;
    }
}
#pragma endregion Group Vignnette Filter

void renderMaster()
{
    // Render code here.
    renderBackdrop();       // Backdrop
    rederWatchStrap();      // Watch Strap
    renderVignetteFilter(); // Vignette Filter
    renderWatchBody();      // Watch Body
    renderBackground();     // Seconds and Outer Ring
    renderWatermelon();     // Watermelon, background wallpaper

    renderCenterPiece();  // Minutes and Analog Indicator
    renderHour();         // Hour
    renderComplication(); // Complication (Date, Day, Heart, Battery, Step)

    renderWatchGlass(); // Watch Glass

    // For debugging purpose
    // glColor4f(COLOR_BLACK);
    // debug.drawCircle(5, 0, 360);

    glFlush();  // Clear all GL executions.
    glFinish(); // Block until all GL executions are completed.
}

void init()
{
    // Initialize the windows
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);                 // Set the display mode to single buffer and RGBA.
    glutInitWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);            // Set the windows size.
    glutInitWindowPosition(WINDOWS_INIT_X, WINDOWS_INIT_Y);       // Set the windows position.
    glutCreateWindow("Watermelonish Watchface v1.0 by @cheahPC"); // Set the windows title.

    // Initialize the rendering context
    glClearColor(COLOR_GREEN_LIGHT);                   // Set the background color to white, any area not rendered will be white.
    glMatrixMode(GL_PROJECTION);                       // Set the matrix mode to projection.
    glEnable(GL_LINE_SMOOTH);                          // Enables line anti-aliasing.
    glEnable(GL_BLEND);                                // Enable for proper transparency render.
    glDisable(GL_DEPTH_TEST);                          // Disable depth testing for overlap object. Use for transparency object involved.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Enable transparency.
    Object::glEndReset();                              // Reset the matrix.
    glClear(GL_COLOR_BUFFER_BIT);                      // Load frame buffer.
}
