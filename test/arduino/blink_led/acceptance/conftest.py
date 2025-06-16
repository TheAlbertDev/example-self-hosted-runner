import pytest
import time
import RPi.GPIO as GPIO

@pytest.fixture(scope="function")
def setup_gpio():
    """Setup and teardown for GPIO testing."""
    # Set the pin numbering mode (also set in each test for safety)
    GPIO.setwarnings(False)  # Disable warnings about channels in use
    try:
        GPIO.setmode(GPIO.BCM)
    except:
        # If already set, this might throw an error - ignore it
        pass
    
    # GPIO 2 will be set as an input (no pull-up/down as it uses push-pull driver)
    GPIO.setup(2, GPIO.IN)
    
    yield
    
    # Clean up GPIO settings after tests
    GPIO.cleanup()
