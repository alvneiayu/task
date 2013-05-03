static int nft_data_reg_value_snprintf_json(char *buf, size_t size,
					   union nft_data_reg *reg,
					   uint32_t flags)
{
	int len = size, offset = 0, ret, i, j;
	uint8_t *tmp;
	int data_len = reg->len/sizeof(uint32_t);

	ret = snprintf(buf, len, "{ \"data_reg\": { \"type\" : \"value\",");
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	ret = snprintf(buf+offset, len, "\"len\" : %d,", data_len);
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	for (i=0; i<data_len; i++) {
		ret = snprintf(buf+offset, len, "\"data%d\" : \"0x", i);
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

		tmp = (uint8_t *)&reg->val[i];

		for (j=0; j<sizeof(int); j++) {
			ret = snprintf(buf+offset, len, "%.02x", tmp[j]);
			SNPRINTF_BUFFER_SIZE(ret, size, len, offset);
		}

		ret = snprintf(buf+offset, len, "\"", i);
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);
	}

	ret = snprintf(buf+offset, len, "}}");
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	return offset;
}
