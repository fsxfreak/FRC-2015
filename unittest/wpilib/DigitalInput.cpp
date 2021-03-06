/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "DigitalInput.h"
#include "Resource.h"

/**
 * Create an instance of a DigitalInput.
 * Creates a digital input given a channel. Common creation routine for all
 * constructors.
 */
void DigitalInput::InitDigitalInput(uint32_t channel)
{
	char buf[64];

	if (!CheckDigitalChannel(channel))
	{
		snprintf(buf, 64, "Digital Channel %d", channel);
		return;
	}
	m_channel = channel;

	int32_t status = 0;
	allocateDIO(m_digital_ports[channel], true, &status);

	HALReport(HALUsageReporting::kResourceType_DigitalInput, channel);
}

/**
 * Create an instance of a Digital Input class.
 * Creates a digital input given a channel.
 *
 * @param channel The DIO channel 0-9 are on-board, 10-25 are on the MXP port
 */
DigitalInput::DigitalInput(uint32_t channel)
{
	InitDigitalInput(channel);
}

/**
 * Free resources associated with the Digital Input class.
 */
DigitalInput::~DigitalInput()
{
	if (m_interrupt != NULL)
	{
		int32_t status = 0;
		cleanInterrupts(m_interrupt, &status);
		m_interrupt = NULL;
		m_interrupts->Free(m_interruptIndex);
	}

	int32_t status = 0;
	freeDIO(m_digital_ports[m_channel], &status);
}

/**
 * Get the value from a digital input channel.
 * Retrieve the value of a single digital input channel from the FPGA.
 */
bool DigitalInput::Get()
{
	int32_t status = 0;
	bool value = getDIO(m_digital_ports[m_channel], &status);
	return value;
}

/**
 * @return The GPIO channel number that this object represents.
 */
uint32_t DigitalInput::GetChannel()
{
	return m_channel;
}

/**
 * @return The value to be written to the channel field of a routing mux.
 */
uint32_t DigitalInput::GetChannelForRouting()
{
	return GetChannel();
}

/**
 * @return The value to be written to the module field of a routing mux.
 */
uint32_t DigitalInput::GetModuleForRouting()
{
	return 0;
}

/**
 * @return The value to be written to the analog trigger field of a routing mux.
 */
bool DigitalInput::GetAnalogTriggerForRouting()
{
	return false;
}
