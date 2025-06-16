import pytest
import time
import RPi.GPIO as GPIO
import sys

def test_gpio_2_toggles_every_second(setup_gpio):
    """Test that GPIO pin 2 toggles every second."""
    # Ensure GPIO mode is set (this is required by RPi.GPIO)
    # Disable warnings about channels already in use
    GPIO.setwarnings(False)
    
    # Print GPIO information for debugging
    print(f"Testing with RPi.GPIO version: {GPIO.VERSION}")
    print(f"Running on Python: {sys.version}")
    
    # Set mode and handle possible errors
    try:
        GPIO.setmode(GPIO.BCM)
        print("GPIO mode set to BCM")
    except Exception as e:
        print(f"Warning setting GPIO mode: {e}")
        # Continue anyway, as the mode may have been set in the fixture
    
    # List to store the timestamps of transitions
    transitions = []
    
    # Make sure GPIO 2 is set up correctly - no pull-up/down as it's using push-pull driver
    try:
        GPIO.setup(2, GPIO.IN)
        print("GPIO 2 configured as input (no pull resistor)")
    except Exception as e:
        print(f"Warning when setting up GPIO 2: {e}")
    
    # Initial state - handle potential errors
    try:
        last_state = GPIO.input(2)
        print(f"Initial GPIO 2 state: {last_state}")
    except Exception as e:
        pytest.fail(f"Failed to read GPIO 2: {e}. Make sure RPi.GPIO is properly set up.")
    
    # Monitor for 5 seconds (should see about 5 transitions)
    start_time = time.time()
    timeout = start_time + 5
    
    while time.time() < timeout:
        try:
            current_state = GPIO.input(2)
            
            # If state changed, record the timestamp
            if current_state != last_state:
                transition_time = time.time()
                transitions.append(transition_time)
                print(f"Transition detected at {transition_time-start_time:.2f}s: {last_state} -> {current_state}")
                last_state = current_state
        except Exception as e:
            print(f"Error reading GPIO: {e}")
            time.sleep(0.1)  # Longer delay on error
        
        # Small delay to avoid hogging CPU
        time.sleep(0.01)
    
    # Calculate time between transitions
    intervals = []
    for i in range(1, len(transitions)):
        interval = transitions[i] - transitions[i-1]
        intervals.append(interval)
    
    # Check if we have enough transitions
    assert len(transitions) >= 4, f"Not enough transitions detected: {len(transitions)}"
    
    # Calculate average interval
    avg_interval = sum(intervals) / len(intervals)
    
    # Print for debugging
    print(f"Detected {len(transitions)} transitions")
    print(f"Average interval: {avg_interval:.3f} seconds")
    print(f"Intervals: {[round(i, 3) for i in intervals]}")
    
    # Check if the average interval is close to 1 second (allowing 0.2 seconds tolerance)
    assert 0.8 <= avg_interval <= 1.2, f"Average toggle interval {avg_interval:.3f} is not close to 1 second"
