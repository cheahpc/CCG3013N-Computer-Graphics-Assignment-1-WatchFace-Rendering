

// Include custom headers
#include "object.cpp"

// Group Background
Object background = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object seconds = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object outerRing = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

// Group Center Circles
Object coreCircle = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object minutes = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object analogQuaterIndicator = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object analogIndicator = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textAMPM = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textMinute = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

// Group Date and Day
Object dayBox = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object dateBox = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textDate = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textDay = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

// Group Heart
Object iconHeart = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textHeartRate = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

// Group Battery
Object iconBattery = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textBattery = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

// Group Step
Object textStepCount = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textStepUnit = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

// Group Hour
Object hourCircle = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object hourPointer = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textHour = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

// Group Seed
Object seed = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderMaster()
{
    // Render code here.
    // Group Background
    glColor4f(COLOR_WHITE);
    background.drawCircle(BAKGROUND_CIRCLE_RADIUS, 0, 360);
    glColor4f(COLOR_RED);
    seconds.drawTorus(SECONDS_RING_RADIUS, SECONDS_RING_THICKNESS, 0, 194);
    glColor4f(COLOR_GREEN);
    outerRing.drawTorus(OUTER_RING_RADIUS, OUTER_RING_THICKNESS, 0, 360);

#pragma region Group Center Circles
    // =============================================== Group Center Circles
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
    // =============================================== Group Center Circles
#pragma endregion Group Center Circles

#pragma region Group Hour
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
#pragma endregion Group Hour

#pragma region Group Date and Day
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
#pragma endregion Group Date and Day

#pragma region Group Heart
    // =============================================== Group Heart
    glColor4f(COLOR_RED);
    iconHeart.translate(-90, COMPLICATION_RING_RADIUS);
    iconHeart.drawHeart(20);

    glColor4f(COLOR_GREY);
    textHeartRate.translate(-50, COMPLICATION_RING_RADIUS - 10);
    textHeartRate.scale(0.25);
    textHeartRate.drawText("76bpm", 4);
    // =============================================== Group Heart
#pragma endregion Group Heart

#pragma region Group Battery
    // =============================================== Group Battery
    textBattery.translate(-10, -COMPLICATION_RING_RADIUS - 15);
    textBattery.scale(0.25);
    textBattery.drawText("60%", 4);

    glColor4f(COLOR_BLACK);
    iconBattery.translate(-35, -COMPLICATION_RING_RADIUS);
    // iconBattery.scale(0.2);
    iconBattery.drawBattery(20, 2, 1, 60);
    // =============================================== Group Battery
#pragma endregion Group Battery

#pragma region Group Step
    glColor4f(COLOR_GREY);
    textStepCount.translate(-COMPLICATION_RING_RADIUS - 50, 0);
    textStepCount.scale(0.35);
    textStepCount.drawText("4896", 6);

    glColor4f(COLOR_RED);
    textStepUnit.translate(-COMPLICATION_RING_RADIUS - 4, -28);
    textStepUnit.scale(0.15);
    textStepUnit.drawText("Step", 3);
#pragma endregion Group Step
    glColor4f(COLOR_GREY);
    seed.drawTautBelt(80, 20, 150);
    glFlush();  // Clear all GL executions.
    glFinish(); // Block until all GL executions are completed.
}

void init()
{
    // Initialize the windows
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);
    glutInitWindowPosition(WINDOWS_INIT_X, WINDOWS_INIT_Y);
    glutCreateWindow(WINDOWS_TITTLE);

    // Initialize the rendering context
    // glClearColor(COLOR_WHITE);                       // Set the background color to white.
    glMatrixMode(GL_PROJECTION);  // Set the matrix mode to projection.
    Object::glEndReset();         // Reset the matrix.
    glClear(GL_COLOR_BUFFER_BIT); // Load frame buffer.
}
