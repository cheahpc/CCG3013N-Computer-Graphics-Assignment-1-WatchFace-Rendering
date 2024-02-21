// Include custom headers
#include "object.cpp"

// Group Background
#pragma region Group Background
Object background = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object seconds = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object outerRing = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

Object watermelonShellA = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonShellB = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonFleshA = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonFleshB = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonSeed = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderBackground()
{
    glColor4f(COLOR_WHITE);
    background.drawCircle(BAKGROUND_CIRCLE_RADIUS, 0, 360);
    glColor4f(COLOR_RED);
    seconds.drawTorus(SECONDS_RING_RADIUS, SECONDS_RING_THICKNESS, 0, 194);
    glColor4f(COLOR_GREEN);
    outerRing.drawTorus(OUTER_RING_RADIUS, OUTER_RING_THICKNESS, 0, 360);
}

void renderWatermelon()
{
    // Watermelon Shell
    glColor4f(0.8f, 0.4f, 0.2f, 0.7f); // Set color to transparently green
    watermelonShellA.drawCircle(100, 135, 315);
    // watermelonShellB.drawCircle(100, 180, 360);

    // Watermelon Flesh
    // glColor4f(COLOR_GREEN);
    // watermelonFleshA.drawCircle(90, 0, 180);
    // watermelonFleshB.drawCircle(90, 180, 360);

    // Watermelon Seed
    // glColor4f(COLOR_BLACK);
    // watermelonSeed.drawCircle(10, 0, 360);
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
    glColor4f(COLOR_RED);
    coreCircle.drawCircle(CORE_CIRCLE_RADIUS, 0, 360);
    glColor4f(COLOR_GREEN);
    minutes.drawCircle(MINUTES_CIRCLE_RADIUS, 0, 288);
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

    dateBox.translate(COMPLICATION_RING_RADIUS, 20);
    glColor4f(COLOR_GREEN);
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

// Group Seed
Object seed = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderMaster()
{
    // Render code here.

    renderBackground();   // Seconds and Outer Ring
    renderCenterPiece();  // Minutes and Analog Indicator
    renderHour();         // Hour
    renderComplication(); // Complication (Date, Day, Heart, Battery, Step)

    // TODO draw watermelon a slice or two
    renderWatermelon();

    glFlush();  // Clear all GL executions.
    glFinish(); // Block until all GL executions are completed.
}

void init()
{
    // Initialize the windows
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);
    glutInitWindowPosition(WINDOWS_INIT_X, WINDOWS_INIT_Y);
    glutCreateWindow("Watermelonish Watchface v1.0 by @cheahPC");

    // Initialize the rendering context
    glClearColor(COLOR_WHITE);                         // Set the background color to white, any area not rendered will be white.
    glMatrixMode(GL_PROJECTION);                       // Set the matrix mode to projection.
    glEnable(GL_LINE_SMOOTH);                          // Enables line anti-aliasing.
    glEnable(GL_BLEND);                                // Enable for proper transparency render.
    glDisable(GL_DEPTH_TEST);                          // Disable depth testing for overlap object. Use for transparency object involved.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Enable transparency.
    Object::glEndReset();                              // Reset the matrix.
    glClear(GL_COLOR_BUFFER_BIT);                      // Load frame buffer.
}
